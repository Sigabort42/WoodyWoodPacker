/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i_maxtoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 06:40:59 by elbenkri          #+#    #+#             */
/*   Updated: 2018/01/11 15:57:56 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(intmax_t cpy)
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

static char	*ft_print(char *str, intmax_t n, int *i)
{
	while (n > 0)
	{
		str[*i] = (n % 10) + 48;
		*i = *i - 1;
		n /= 10;
	}
	return (str);
}

char		*ft_lol(void)
{
	return (ft_strdup("-9223372036854775808"));
}

char		*ft_i_maxtoa(intmax_t n)
{
	int				i;
	intmax_t		cpy;
	int				flg;
	char			*str;

	if (n < -9223372036854775807)
	{
		return (str = ft_lol());
	}
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
