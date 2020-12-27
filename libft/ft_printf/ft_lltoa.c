/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 06:40:59 by elbenkri          #+#    #+#             */
/*   Updated: 2017/12/19 20:29:31 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(unsigned long long cpy)
{
	int		i;

	i = 0;
	while (cpy >= 10)
	{
		cpy /= 10;
		i++;
	}
	i++;
	return (i);
}

static char	*ft_print(char *str, unsigned long long n, int *i)
{
	while (n > 0)
	{
		str[*i] = (n % 10) + 48;
		*i = *i - 1;
		n /= 10;
	}
	return (str);
}

char		*ft_lltoa(unsigned long long n)
{
	int				i;
	long long		cpy;
	int				flg;
	char			*str;

	i = 0;
	flg = ABS(n);
	n = (flg == 0) ? n : n * -1;
	cpy = n;
	i = ft_count(cpy);
	(flg == 1) ? i++ : i;
	if ((str = (char *)malloc(sizeof(*str) * i + 1 + flg)) == 0)
		return (0);
	if (n == 0)
		str[0] = '0';
	str[i--] = '\0';
	str = ft_print(str, n, &i);
	if (flg == 1)
		str[i] = '-';
	return (str);
}
