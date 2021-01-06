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

#define KEY_MASK 0x7
static char key[8] ="ABCDEFGH";

void    xor_block (unsigned char *data, int len)
{
  int i;

  for (i = 0; i < len; data[i] ^= key[i & KEY_MASK], i++);
}

Elf64_Shdr      *find_section(void *data, char *name)
{
  char		*sname;
  int		i;
  Elf64_Ehdr	*elf_hdr;
  Elf64_Shdr	*shdr;
  Elf64_Shdr	*sh_strtab;
  char		*sh_strtab_p;
  
  elf_hdr = (Elf64_Ehdr *)data;
  shdr = (Elf64_Shdr *)(data + elf_hdr->e_shoff);
  sh_strtab = &shdr[elf_hdr->e_shstrndx];
  sh_strtab_p = data + sh_strtab->sh_offset;
  ft_printf ("+ %d section in file. Looking for section '%s'\n", elf_hdr->e_shnum, name);
  for (i = 0; i < elf_hdr->e_shnum; i++)
    {
      sname = (char*) (sh_strtab_p + shdr[i].sh_name);
      if (!strcmp (sname, name))
	  return &shdr[i];
    }

  return (0);
}

int	packing32(t_env *env)
{
  printf("Launch ELF 32 %p\n", env);
  return (0);
}

int	packing64(t_env *env)
{
  Elf64_Phdr    *seg;
  int           i;

  i = 0;
  seg = (Elf64_Phdr*)((char*)env->ptr + (unsigned int)env->elf64->e_phoff);
  env->old_vaddr64 = env->elf64->e_entry;
  while (i < env->elf64->e_phnum)
    {
      if (seg->p_type == PT_LOAD && seg->p_flags & PF_W)
	break;
      seg = (Elf64_Phdr*)((char*)seg + (unsigned int) env->elf64->e_phentsize);
      i++;
    }
  env->sec64 = find_section(env->ptr_payload, ".text");
  //  xor_block (env->ptr + env->sec64->sh_offset, env->sec64->sh_size);
  if ((i = inject(env)) != 0)
    return (i);
  ft_printf("++ FILE CREATED: %s\n++ KEY: %s\n", key, env->name_output);
  return (0);
}


int     woody(t_env *env)
{
  env->elf64 = (Elf64_Ehdr*)env->ptr;
  if (env->elf64->e_ident[0] == ELFMAG0 &&
      env->elf64->e_ident[1] == ELFMAG1 &&
      env->elf64->e_ident[2] == ELFMAG2 &&
      env->elf64->e_ident[3] == ELFMAG3 &&
      env->elf64->e_type == ET_EXEC)
    {
      if (env->elf64->e_ident[EI_CLASS] == ELFCLASS64)
	return packing64(env);
      else if (env->elf64->e_ident[EI_CLASS] == ELFCLASS32)
	return packing32(env);
    }
  else
    {
      ft_printf("%s\n", "Error: File is not ELF Executable or PIE activate");
      return (-1);
    }
  return (0);
}
