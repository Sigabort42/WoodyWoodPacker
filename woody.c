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

int	run_packing32(Elf32_Ehdr *elf, void *ptr)
{
	ft_printf("%s %p %p\n", "Launch Packer Woody 32", elf, ptr);
	return (0);
}

int	run_packing64(Elf64_Ehdr *elf, void *ptr)
{
	ft_printf("%s %p %p\n", "Launch Packer Woody 64", elf, ptr);
	return (0);
}

int	woody(void *ptr)
{
	Elf64_Ehdr	*elf;

	elf = ptr;
	if (elf->e_ident[0] == ELFMAG0 &&
	elf->e_ident[1] == ELFMAG1 &&
	elf->e_ident[2] == ELFMAG2 &&
	elf->e_ident[3] == ELFMAG3 &&
	elf->e_type == ET_EXEC)
	{
		if (elf->e_ident[EI_CLASS] == ELFCLASS64)
			run_packing64(elf, ptr);
		else if (elf->e_ident[EI_CLASS] == ELFCLASS32)
			run_packing32((Elf32_Ehdr*)ptr, ptr);
	}
	else
	{
		ft_printf("%s\n", "Error: File is not ELF Executable");
		return (1);
	}
	return (0);
}
