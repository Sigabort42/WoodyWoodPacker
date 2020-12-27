/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 22:00:41 by elbenkri          #+#    #+#             */
/*   Updated: 2017/12/13 14:18:58 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin_free(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (s1 == NULL && s2 == NULL)
		return (0);
	if (s1 == NULL)
		str = (char *)malloc(sizeof(char) * ft_strlen(s2) + 1);
	else if (s2 == NULL)
		str = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	else
		str = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	while (s1 != 0 && s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2 != 0 && s2[i])
		str[j++] = s2[i++];
	str[j] = 0;
	if (s1 != 0)
		free(s1);
	if (s2 != 0)
		free(s2);
	return (str);
}
