/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_printf2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:48:30 by elbenkri          #+#    #+#             */
/*   Updated: 2018/02/02 16:54:04 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_return_printf2(const char *format, va_list ap, t_var *var)
{
	if (ft_printf2(format, ap, var) == -1)
	{
		ft_free(var);
		return (-1);
	}
	return (0);
}
