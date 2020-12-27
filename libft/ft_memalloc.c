/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 01:09:07 by elbenkri          #+#    #+#             */
/*   Updated: 2017/11/13 21:17:00 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char			*str;
	size_t			i;

	i = 0;
	if (size > 4294967295)
		return (0);
	if ((str = (char*)malloc(sizeof(*str) * size + 1)) == 0)
		return (0);
	while (i < size)
		str[i++] = 0;
	return ((void *)str);
}
