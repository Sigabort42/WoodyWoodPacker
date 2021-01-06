#include "./includes/woody.h"

void		infect_section(t_env *env, Elf64_Addr text_end, Elf64_Addr payload_vaddr)
{
  Elf64_Shdr* shdr;
  int		payload_len;

  payload_len = env->sec64->sh_size;
  shdr = (Elf64_Shdr*) (env->ptr + env->elf64->e_shoff);
  env->elf64->e_shoff += PAGE_SZ64;
  for(int i=0; i < env->elf64->e_shnum; i++)
    {
      if(shdr[i].sh_offset > text_end)
	shdr[i].sh_offset += PAGE_SZ64;       
      else if(shdr[i].sh_addr + shdr[i].sh_size == payload_vaddr)
	shdr[i].sh_size += payload_len;
    }

}


Elf64_Addr	infect_segment(t_env *env, Elf64_Addr *text_end)
{
  Elf64_Phdr	*phdr;
  Elf64_Addr	payload_vaddr;
  int		payload_len;

  payload_vaddr = 0;
  payload_len = env->sec64->sh_size;
  phdr = (Elf64_Phdr*) (env->ptr + env->elf64->e_phoff);
  for(int i=0; i < env->elf64->e_phnum; i++)
    {
      if(phdr[i].p_type == PT_LOAD && phdr[i].p_flags == (PF_R | PF_X))
	{
	  *text_end = phdr[i].p_offset + phdr[i].p_filesz;
	  payload_vaddr = phdr[i].p_vaddr + phdr[i].p_filesz;
	  env->elf64->e_entry = payload_vaddr;
	  phdr[i].p_filesz += payload_len;
	  phdr[i].p_memsz += payload_len;
	  for(int j=i+1; j < env->elf64->e_phnum; j++)
	    phdr[j].p_offset += PAGE_SZ64;
	  break;
	}
    }
  return (payload_vaddr);
}

char	*infect(t_env *env, int elf_len, char* payload, int payload_len)
{
  char* new_file = malloc(elf_len + PAGE_SZ64);
  char jmp_entry[] = "\x48\xb8\x41\x41\x41\x41\x41\x41\x41\x41" //mov rax,0x4141414141414141
    "\xff\xe0"; // jmp rax
  int jmp_len = 12;
  payload_len += jmp_len;

  Elf64_Addr entry, payload_vaddr, text_end;


  entry = env->elf64->e_entry;


  payload_vaddr = infect_segment(env, &text_end);
  infect_section(env, text_end, payload_vaddr);

  memcpy(&jmp_entry[2], (char*)&entry, 8);
  memcpy(new_file, env->ptr, (size_t) text_end);
  memcpy(new_file + text_end, payload, payload_len - jmp_len);
  memcpy(new_file + text_end + payload_len - jmp_len, jmp_entry, jmp_len);
  memcpy(new_file + text_end + PAGE_SZ64, env->ptr + text_end, elf_len - text_end);

  return new_file;
}


int	inject(t_env *env)
{
  char	*new_file;
  int	fd;

  new_file = infect(env, env->buf.st_size, env->ptr_payload + env->sec64->sh_offset, env->sec64->sh_size);
  if ((fd = open(env->name_output, O_RDWR | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO)) < 0)
    return (2);
  write(fd, new_file, env->buf.st_size + PAGE_SZ64);
  return (0);
}
