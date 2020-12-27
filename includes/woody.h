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

#include <unistd.h>
# include <sys/mman.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdlib.h>
# include "./elf.h"
# include "../libft/libft.h"

int	run_packing(Elf64_Ehdr *elf, void *ptr);
int	woody(void *ptr);
