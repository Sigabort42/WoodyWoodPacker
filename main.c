/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <elbenkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 01:14:34 by elbenkri          #+#    #+#             */
/*   Updated: 2020/12/27 01:14:37 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/woody.h"

int	run(char *file)
{
	struct stat     buf;
        int             fd;
        void            *ptr;

        if ((fd = open(file, O_RDONLY)) < 0)
                return (1);
        if (fstat(fd, &buf) < 0)
                return (2);
        if ((ptr = mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) ==
                MAP_FAILED)
                return (3);
        woody(ptr);
        if (munmap(ptr, buf.st_size) < 0)
                return (4);
        return (0);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		ft_printf("%s\n", "./woody FILE");
	run(av[1]);
	return (0);
}
