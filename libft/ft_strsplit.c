/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 03:13:48 by elbenkri          #+#    #+#             */
/*   Updated: 2017/11/14 04:35:30 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		ft_count_words(char const *s, char c, int *j)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] && s[i] != c)
		{
			i++;
			*j = *j + 1;
		}
		while (s[i] == c)
			i++;
		k++;
	}
	return (k);
}

static void		ft_ok(char const *s, char c, int *l)
{
	while (s[*l] == c)
		*l = *l + 1;
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		k;
	int		j;
	int		l;
	char	**tab;

	i = 0;
	j = 0;
	l = 0;
	if (s == 0)
		return (0);
	if (!(tab = (char **)malloc(sizeof(tab) * ft_count_words(s, c, &j) + 1)))
		return (0);
	ft_ok(s, c, &l);
	while (s[l])
	{
		k = 0;
		tab[i] = (char *)malloc(sizeof(*tab) * j + 1);
		while (s[l] && s[l] != c)
			tab[i][k++] = s[l++];
		ft_ok(s, c, &l);
		tab[i++][k] = 0;
	}
	tab[i] = 0;
	return (tab);
}
