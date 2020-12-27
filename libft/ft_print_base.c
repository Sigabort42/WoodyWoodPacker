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

#include "libft.h"

char			*ft_print_base(unsigned int value, int base)
{
	char		*res;
	int			i;

	res = NULL;
	i = 2;
	if (base == 10)
		return (res = ft_itoa(value));
	res = (char*)malloc(sizeof(char) * i);
	res[i] = 0;
	while (i-- > 0)
	{
		res[i] = value % base + ((value % base > 9) ? 'a' - 10 : '0');
		value /= base;
	}
	ft_putstr(res);
	ft_putstr(" ");
	return (res);
}
