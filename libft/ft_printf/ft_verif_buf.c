/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_buf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:24:42 by elbenkri          #+#    #+#             */
/*   Updated: 2018/02/02 14:57:49 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_verif_buf(t_var *var, const char *format)
{
	if (var->i_buf > 10000)
	{
		write(1, var->buf, 10000);
		var->i_buf = 0;
		ft_bzero(var->buf, 10000);
	}
	var->ret += ft_stock_flags(&((char*)format)[var->ret], var);
}
