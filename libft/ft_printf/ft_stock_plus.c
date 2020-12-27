/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_plus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 19:44:08 by elbenkri          #+#    #+#             */
/*   Updated: 2018/01/08 19:45:05 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_stock_plus(t_var *var, t_flags *s_flags, char *str_hexa)
{
	if (str_hexa[0] != '-' && s_flags->c & (1 << 1) && var->type <= TYPE_INT)
	{
		var->buf_tmp[var->i_buf_tmp++] = '+';
		return (1);
	}
	return (0);
}
