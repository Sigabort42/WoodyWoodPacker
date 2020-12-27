/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 12:45:52 by elbenkri          #+#    #+#             */
/*   Updated: 2017/12/28 13:30:28 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int		ft_count(int value, int base)
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

char			*ft_itoa_base(int value, int base)
{
	char		*res;
	int			i;

	res = NULL;
	if (base == 10)
		return (res = ft_itoa(value));
	value = (value < 0) ? (unsigned int)value : value;
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
