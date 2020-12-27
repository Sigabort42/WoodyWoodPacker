/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:25:10 by elbenkri          #+#    #+#             */
/*   Updated: 2017/11/13 21:05:41 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	c;

	j = 0;
	i = ft_strlen(str);
	while (i >= j)
	{
		c = str[--i];
		str[i] = str[j];
		str[j++] = c;
	}
	str[j + i] = '\0';
	return (str);
}
