/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:47:22 by elbenkri          #+#    #+#             */
/*   Updated: 2017/11/13 23:43:24 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;

	i = ft_strlen((char*)s);
	if (s[0] == c && !s[0])
		return ((char*)s);
	if (s[0])
	{
		while (i >= 0)
		{
			if (s[i] == c)
				return ((char*)&s[i]);
			i--;
		}
	}
	return (0);
}
