/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 00:28:38 by elbenkri          #+#    #+#             */
/*   Updated: 2017/11/13 21:20:38 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	if ((str = (unsigned char *)malloc(sizeof(*str) * size + 1)) == 0)
		return (0);
	while (i <= size)
		str[i++] = 0;
	return ((char*)str);
}
