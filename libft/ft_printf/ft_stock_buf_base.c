/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_buf_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 20:19:16 by elbenkri          #+#    #+#             */
/*   Updated: 2018/01/20 14:47:51 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_stock_buf_base2(t_var *var, t_flags *s_flags, int res_strcmp)
{
	int		i;
	int		o;

	i = 0;
	o = (var->type >= TYPE_OCTAL && var->type <= TYPE_OCTAL_MAJ);
	if ((s_flags->c & (1 << 4)) && o && ((res_strcmp && !s_flags->precision
	&& ft_strchr(var->flags_stock, '.')) || !ft_strchr(var->flags_stock, '.')))
	{
		i = 1;
		ft_memcpy(&var->buf_tmp[var->i_buf_tmp], "0", i);
		var->i_buf_tmp += i;
	}
	return (i);
}

void		ft_stock_buf_base3(t_var *var, t_flags *s_flags)
{
	int		i;
	int		x;
	int		x2;

	x = (var->type >= TYPE_OCTAL && var->type <= TYPE_OCTAL_MAJ);
	x2 = s_flags->largeur - s_flags->precision;
	i = s_flags->largeur - s_flags->precision;
	if (var->i_plus && !(s_flags->c &= (1 << 0)))
		var->buf[var->i_buf++] = '+';
	if (((!ft_strchr(var->flags_stock, '.') && !s_flags->precision && !x) ||
	(x && s_flags->c < 16) || (ft_strchr(var->flags_stock, '.') &&
				s_flags->precision && x2 > var->len_str_hexa)))
	{
		if (!ft_strchr(var->flags_stock, '.'))
			var->buf[var->i_buf++] = '0';
	}
}

int			ft_stock_buf_base(t_var *var, t_flags *s_flags, int res_strcmp)
{
	int		i;

	i = 0;
	if (!res_strcmp && s_flags->m == 0 && s_flags->c >= 2 &&
	s_flags->c <= 16 && (!var->i_buf || (var->type >= TYPE_OCTAL &&
						var->type <= TYPE_OCTAL_MAJ)))
		ft_stock_buf_base3(var, s_flags);
	else if (((s_flags->c & (1 << 4)) && (var->type >= TYPE_HEXA &&
	var->type <= TYPE_HEXA_MAJ) && res_strcmp) || var->type == TYPE_ADDRESS)
	{
		i = 2;
		if ((var->type == TYPE_HEXA) || var->type == TYPE_ADDRESS)
			ft_memcpy(&var->buf_tmp[var->i_buf_tmp], "0x", var->i_buf_tmp += i);
		else if (var->type == TYPE_HEXA_MAJ)
		{
			ft_memcpy(&var->buf_tmp[var->i_buf_tmp], "0X", i);
			var->i_buf_tmp += i;
		}
	}
	else
		i = ft_stock_buf_base2(var, s_flags, res_strcmp);
	return (i);
}
