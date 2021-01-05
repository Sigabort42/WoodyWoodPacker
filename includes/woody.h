/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woody.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <elbenkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 01:14:27 by elbenkri          #+#    #+#             */
/*   Updated: 2020/12/27 01:14:29 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
# include <sys/mman.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdlib.h>
# include "./elf.h"
# include "../libft/libft.h"

typedef struct			s_env
{
	char			*name_output;
	struct stat		buf;
  	struct stat		buf_payload;
       	void			*ptr;
  	void			*ptr_payload;
	Elf64_Ehdr		*elf64;
  	Elf64_Shdr		*sec64;
	Elf64_Addr		old_vaddr64;
	Elf32_Ehdr		*elf32;
	unsigned long long	p;
	unsigned long long	len;
	int			fd;
	int			fd2;	
}				t_env;

int				woody(t_env *env);
int				inject(t_env *env);
