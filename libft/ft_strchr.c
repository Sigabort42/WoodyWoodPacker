/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:47:22 by elbenkri          #+#    #+#             */
/*   Updated: 2017/11/13 22:43:38 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;

	if (s[0] == c)
		return ((char *)s);
	if (s[0])
	{
		i = 0;
		while (s[i])
		{
			if (s[i] == c)
				return ((char*)&s[i]);
			i++;
		}
		if (s[i] == c)
			return ((char*)&s[i]);
	}
	return (0);
}
