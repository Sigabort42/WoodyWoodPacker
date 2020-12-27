/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 04:32:27 by elbenkri          #+#    #+#             */
/*   Updated: 2017/11/14 04:22:38 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_isokend(char const *s, int *i)
{
	while (s[*i] == ' ' || s[*i] == '\t' || s[*i] == '\n')
		*i = *i - 1;
}

static void	ft_isok(char const *s, int *i)
{
	while (s[*i] == ' ' || s[*i] == '\t' || s[*i] == '\n')
		*i = *i + 1;
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		k;
	int		j;
	char	*str;

	i = 0;
	k = 0;
	if (s == 0)
		return (0);
	j = ft_strlen(s) - 1;
	ft_isok(s, &i);
	if (s[i] == 0)
	{
		if ((str = (char *)malloc(sizeof(*str))) == 0)
			return (0);
		str[0] = (str != 0) ? '\0' : str[0];
		return ((char*)str);
	}
	ft_isokend(s, &j);
	if ((str = (char *)malloc(sizeof(*str) * ++j - i + 1)) == 0)
		return (0);
	while (i < j)
		str[k++] = s[i++];
	str[k] = '\0';
	return (str);
}
