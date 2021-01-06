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

int	run(char *file, char *payload, char *name)
{
  t_env		env;

  env.name_output = ft_strdup(name);
  if ((env.fd = open(file, O_RDWR)) < 0)
    return (1);
  if (fstat(env.fd, &env.buf) < 0)
    return (2);
  if ((env.ptr = mmap(0, env.buf.st_size, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE, env.fd, 0)) == MAP_FAILED)
    return (3);
  if (ft_strcmp(payload, ""))
    {
      if ((env.fd2 = open(payload, O_RDWR)) < 0)
	return (4);
      if (fstat(env.fd2, &env.buf_payload) < 0)
	return (5);
      if ((env.ptr_payload = mmap(0, env.buf_payload.st_size, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_SHARED, env.fd2, 0)) == MAP_FAILED)
	return (6);
    }
  woody(&env);
  if (munmap(env.ptr, env.buf.st_size) < 0)
    return (7);
  return (0);
}

int	main(int ac, char **av)
{	
  if (ac < 2)
    {
      ft_printf("%s FILE [PAYLOAD] [NAME OUTPUT]", av[0]);
      return (1);
    }
  else if (ac > 3)
    return run(av[1], av[2], av[3]);
  else if (ac > 2)
    return run(av[1], av[2], "woody");
  else
    return run(av[1], "", "woody");
}
