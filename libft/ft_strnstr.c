/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:47:22 by elbenkri          #+#    #+#             */
/*   Updated: 2017/11/13 02:31:40 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	k = ft_strlen(s2);
	while (s1[i] != '\0' && len-- >= k)
	{
		if (s1[i] == s2[0] && ft_memcmp(&s1[i], s2, k) == 0)
			return ((char *)&s1[i]);
		i++;
	}
	return (0);
}
