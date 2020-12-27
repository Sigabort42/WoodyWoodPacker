/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i_maxtoa_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 12:45:52 by elbenkri          #+#    #+#             */
/*   Updated: 2018/01/11 15:58:58 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_count(intmax_t value, int base)
{
	int		i;

	i = 0;
	if (value == 0)
		return (1);
	while (value > 0)
	{
		i++;
		value /= base;
	}
	return (i);
}

char			*ft_i_maxtoa_base(intmax_t value, int base)
{
	char		*res;
	int			i;

	res = NULL;
	if (base == 10)
		return (ft_i_maxtoa(value));
	value = (value < 0) ? (uintmax_t)value : value;
	i = ft_count(value, base);
	res = (char*)malloc(sizeof(char) * i);
	res[i] = 0;
	while (i-- > 0)
	{
		res[i] = value % base + ((value % base > 9) ? 'a' - 10 : '0');
		value /= base;
	}
	return (res);
}
