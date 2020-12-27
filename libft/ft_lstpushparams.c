/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushparams.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 20:16:44 by elbenkri          #+#    #+#             */
/*   Updated: 2017/11/13 20:29:47 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstpushparams(int argc, char **argv)
{
	size_t		i;
	t_list		*lst;
	t_list		*elem;

	i = 0;
	if (argc < 1)
		return (0);
	lst = ft_lstnew(argv[i], ft_strlen(argv[i]));
	i++;
	while (argv[i])
	{
		elem = ft_lstnew(argv[i], ft_strlen(argv[i]));
		ft_lstpushback(&lst, elem);
		i++;
	}
	return (lst);
}
