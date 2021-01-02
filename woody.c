/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woody.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <elbenkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 01:16:49 by elbenkri          #+#    #+#             */
/*   Updated: 2020/12/27 01:16:50 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/woody.h"

void			print_elem_section(t_env *env)
{
  int			i;
  Elf64_Shdr		*sec_head_start;
  Elf64_Shdr		*sec_strtable;
  Elf64_Shdr		sec_head;
  char			*str;
  
  sec_head_start = env->ptr + env->elf64->e_shoff;
  sec_strtable = sec_head_start + env->elf64->e_shstrndx;
  str = env->ptr + sec_strtable->sh_offset;
  i = 0;
  while (i < env->elf64->e_shnum)
  {
    sec_head = sec_head_start[i];
    printf("section name %s %lu %lx\n", str + sec_head.sh_name, sec_head.sh_size, sec_head.sh_addr);
    i++;
  }
}

Elf64_Phdr		*elf_find_space(t_env *env)
{
	Elf64_Phdr			*elf_seg;
	int				i;
	unsigned long long     		text_end;
	unsigned long long		gap;

	gap = env->buf.st_size;
	i = 0;
	elf_seg = (Elf64_Phdr*)((char*)env->ptr + (unsigned int)env->elf64->e_phoff);
	while (i < env->elf64->e_phnum)
	{
		if (elf_seg->p_type == PT_LOAD && elf_seg->p_flags & 0x11)
		{
			printf("+ Found .text segment (#%d)\n", i);
			env->text_seg64 = elf_seg;
			text_end = elf_seg->p_offset + elf_seg->p_filesz;
		}
		else if (elf_seg->p_type == PT_LOAD &&
			(elf_seg->p_offset - text_end) < gap)
		{
			printf(
		     "*  Found LOAD Segment (#%d) close to .text (offset: 0x%x)\n",
		     i, (unsigned int)elf_seg->p_offset);

			gap = elf_seg->p_offset - text_end;
		}
		elf_seg = (Elf64_Phdr*)((char*)elf_seg 
			    + (unsigned int) env->elf64->e_phentsize);
		i++;
	}
	env->p = text_end;
	(env->len) = gap;
	printf ("+ .text segment gap at offset 0x%llx(0x%llx bytes available) %p\n", text_end, gap, env->text_seg64);
	//	print_elem_section(env);
	return env->text_seg64;
}

int			run_packing32(t_env *env)
{
	env->elf32 = env->ptr;
	printf("%s %p %p\n", "Launch Packer Woody 32", env->elf32, env->ptr);
	return (0);
}

int			elfi_mem_subst (void *m, int len, long pat, long val)
{
  unsigned char *p = (unsigned char*)m;
  long v;
  int i, r;

  for (i = 0; i < len; i++)
    {
      v = *((long*)(p+i));
      r = v ^pat;

      if (r ==0) 
	{
	  printf ("+ Pattern %lx found at offset %d -> %lx\n", pat, i, val);
	  *((long*)(p+i)) = val;
	  return 0;
	}
    }
  return -1;
}

Elf64_Shdr	*elfi_find_section (void *data, char *name)
{
  char        *sname;
  int         i;
  Elf64_Ehdr* elf_hdr = (Elf64_Ehdr *) data;
  Elf64_Shdr *shdr = (Elf64_Shdr *)(data + elf_hdr->e_shoff);
  Elf64_Shdr *sh_strtab = &shdr[elf_hdr->e_shstrndx];
  const char *const sh_strtab_p = data + sh_strtab->sh_offset;
   
  printf ("+ %d section in file. Looking for section '%s'\n", 
	  elf_hdr->e_shnum, name);
  
  
  for (i = 0; i < elf_hdr->e_shnum; i++)
    {
      sname = (char*) (sh_strtab_p + shdr[i].sh_name);
      if (!strcmp (sname, name))  return &shdr[i];
    }
  
  return NULL;
}

int			run_packing64(t_env *env)
{
	Elf64_Addr  *base;
	Elf64_Shdr *p_text_sec;
	int		fd;
	
	printf("%s %p %p\n", "Launch Packer Woody 64", env->elf64, env->ptr);
	env->text_seg64 = elf_find_space(env);
	base = &(env->text_seg64)->p_vaddr;
	p_text_sec = elfi_find_section(env->ptr_payload, ".text");
	printf ("+ Payload .text section found at %lx (%lx bytes)\n", 
		p_text_sec->sh_offset, p_text_sec->sh_size);

	if (p_text_sec->sh_size > (unsigned long)env->len)
	{
	  printf ("%s\n", "- Payload to big, cannot infect file.");
	  exit (1);
	}
	//	 Copy payload in the segment padding area
	printf("lololol %llu %llu %ld\n", env->p, env->len, env->buf.st_size);
	memmove(env->ptr + env->p, env->ptr_payload + p_text_sec->sh_offset, p_text_sec->sh_size);
	elfi_mem_subst(env->ptr + env->p, p_text_sec->sh_size, 0x11111111, (long)env->elf64->e_entry);
	env->elf64->e_entry = (Elf64_Addr)(base + env->p);
	fd = open("./lol.out", O_RDWR | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
	write(fd, env->ptr, env->buf.st_size);
	close(env->fd);
	close(env->fd2);
	printf("lololol %llu %llu %ld\n", env->p, env->len, env->buf.st_size);
	return (0);
}

int			woody(t_env *env)
{
	env->elf64 = env->ptr;
	if (env->elf64->e_ident[0] == ELFMAG0 &&
	env->elf64->e_ident[1] == ELFMAG1 &&
	env->elf64->e_ident[2] == ELFMAG2 &&
	env->elf64->e_ident[3] == ELFMAG3 &&
	env->elf64->e_type == ET_EXEC)
	{
		if (env->elf64->e_ident[EI_CLASS] == ELFCLASS64)
			run_packing64(env);
		else if (env->elf64->e_ident[EI_CLASS] == ELFCLASS32)
			run_packing32(env);
	}
	else
	{
		printf("%s\n", "Error: File is not ELF Executable");
		return (1);
	}
	return (0);
}
