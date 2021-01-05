#include "./includes/woody.h"
#define PAGE_SZ64 0x2000

char	*infect(char *elf, int elf_len, char* payload, int payload_len)
{
  char* virus = malloc(elf_len + PAGE_SZ64);
  char jmp_entry[] = "\x48\xb8\x41\x41\x41\x41\x41\x41\x41\x41" //mov rax,0x4141414141414141
    "\xff\xe0"; // jmp rax
  int jmp_len = 12;
  payload_len += jmp_len;

  Elf64_Ehdr* hdr;
  Elf64_Phdr* phdr;
  Elf64_Shdr* shdr;
  Elf64_Addr entry, payload_vaddr, text_end;


  hdr = (Elf64_Ehdr*)elf;
  entry = hdr->e_entry;
  phdr = (Elf64_Phdr*) (elf + hdr->e_phoff);
  shdr = (Elf64_Shdr*) (elf + hdr->e_shoff);

  hdr->e_shoff += PAGE_SZ64;
  for(int i=0; i < hdr->e_phnum; i++){
    if(phdr[i].p_type == PT_LOAD && phdr[i].p_flags == (PF_R | PF_X)){
      text_end = phdr[i].p_offset + phdr[i].p_filesz;
      payload_vaddr = phdr[i].p_vaddr + phdr[i].p_filesz;
      hdr->e_entry = payload_vaddr;
      phdr[i].p_filesz += payload_len;
      phdr[i].p_memsz += payload_len;
      for(int j=i+1; j < hdr->e_phnum; j++)
	phdr[j].p_offset += PAGE_SZ64;
      break;
    }
  }
  for(int i=0; i < hdr->e_shnum; i++){
    if(shdr[i].sh_offset > text_end)
      shdr[i].sh_offset += PAGE_SZ64;
        
    else if(shdr[i].sh_addr + shdr[i].sh_size == payload_vaddr)
      shdr[i].sh_size += payload_len;
  }
  memcpy(&jmp_entry[2], (char*)&entry, 8);
  memcpy(virus, elf, (size_t) text_end);
  memcpy(virus + text_end, payload, payload_len - jmp_len);
  memcpy(virus + text_end + payload_len - jmp_len, jmp_entry, jmp_len);
  memcpy(virus + text_end + PAGE_SZ64, elf + text_end, elf_len - text_end);

  return virus;
}


int	inject(t_env *env)
{
  char	*virus;  
  int	fd;

  virus = infect(env->ptr, env->buf.st_size, env->ptr_payload + env->sec64->sh_offset, env->sec64->sh_size);
  if ((fd = open(env->name_output, O_RDWR | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO)) < 0)
    return (2);
  write(fd, virus, env->buf.st_size + PAGE_SZ64);
  return (0);
}
