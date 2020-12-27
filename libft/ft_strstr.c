/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:47:22 by elbenkri          #+#    #+#             */
/*   Updated: 2017/11/09 23:15:20 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;

	if (ft_strcmp(haystack, needle) == 0)
		return ((char*)haystack);
	if (haystack[0])
	{
		i = 0;
		while (needle[i])
		{
			if (needle[i] != haystack[i])
				return (ft_strstr((char*)haystack + 1, needle));
			i = i + 1;
		}
		return ((char*)haystack);
	}
	else
		return (0);
}
