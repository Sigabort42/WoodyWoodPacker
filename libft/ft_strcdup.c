/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 21:52:25 by elbenkri          #+#    #+#             */
/*   Updated: 2017/12/08 10:48:18 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcdup(char *s1, int c)
{
	int		i;
	char	*str;

	i = 0;
	if (s1 == 0)
		return (0);
	while (s1[i] && s1[i] != c)
		i++;
	str = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while (s1[i] && s1[i] != c)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}
