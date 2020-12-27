/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags_buffer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 16:14:24 by elbenkri          #+#    #+#             */
/*   Updated: 2018/02/02 16:28:05 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print_flags_buffer5(t_var *var, int i)
{
	while (var->nb.chr2[i])
		var->res2 += ft_wstrlen(var->nb.chr2[i++]);
	var->res = ft_strnew(var->res2);
	i = 0;
	while (var->nb.chr2[i])
		ft_strcat(var->res, ft_wchar(var->nb.chr2[i++]));
	var->res[var->res2] = 0;
}

static void		ft_print_flags_buffer4(t_var *var, t_flags *s_flags, int res)
{
	char		tab[6];

	if (var->res)
	{
		if (s_flags->precision < (int)ft_strlen(var->res))
			ft_flags_precision(var, s_flags, 0);
		else
			ft_flags_largeur(var, s_flags, 0);
	}
	else
	{
		var->res = ((var->type == TYPE_STRING || var->type == TYPE_WSTRING) &&
					!(s_flags->c & (1 << 0))) ? ft_strcpy(tab, "(null)") : 0;
		ft_flags_precision(var, s_flags, 0);
	}
	if (var->type == TYPE_WCHAR || (var->type == TYPE_CHAR && s_flags->m > 2 &&
									s_flags->m <= 16))
	{
		if (s_flags->largeur > res)
			ft_wchar2(var->nb.chr, var, res);
		else
			ft_wchar2(var->nb.chr, var, 0);
	}
}

static void		ft_print_flags_buffer3(va_list ap, t_var *var, t_flags
								*s_flags, int i)
{
	if (var->type == TYPE_WCHAR || (var->type == TYPE_CHAR && s_flags->m > 2 &&
									s_flags->m <= 16))
	{
		var->nb.u_i = va_arg(ap, unsigned int);
		if (var->nb.u_i > 1114111)
			return ;
		var->nb.chr = (wchar_t)var->nb.u_i;
		var->res2 = ft_wstrlen(var->nb.chr);
		var->res = ft_strnew(var->res2);
	}
	else if (var->type == TYPE_NON_CONNU)
	{
		var->res = &var->nb.c;
		var->res[1] = 0;
	}
	else if (var->type == TYPE_WSTRING || (s_flags->m > 0 && s_flags->m <= 16))
	{
		var->nb.chr2 = (wchar_t*)va_arg(ap, unsigned int*);
		if (var->nb.chr2)
			ft_print_flags_buffer5(var, i);
	}
	ft_print_flags_buffer4(var, s_flags, var->res2);
}

static void		ft_print_flags_buffer2(va_list ap, t_var *var, t_flags *s_flags)
{
	var->res = NULL;
	var->i_buf_tmp = 0;
	if (var->type == TYPE_MODULO)
	{
		var->nb.c = '%';
		var->res = &var->nb.c;
		var->res[1] = 0;
	}
	else if (var->type == TYPE_CHAR && s_flags->m == 0)
	{
		var->nb.c = va_arg(ap, int);
		var->res = &var->nb.c;
		var->res[1] = 0;
	}
	else if (var->type == TYPE_STRING && s_flags->m == 0)
		var->res = va_arg(ap, char*);
	else
	{
		ft_print_flags_buffer3(ap, var, s_flags, 0);
		return ;
	}
	ft_print_flags_buffer4(var, s_flags, 0);
}

int				ft_print_flags_buffer(va_list ap, t_var *var, t_flags *s_flags)
{
	if (var->type >= TYPE_NON_CONNU && var->type <= TYPE_WSTRING)
		ft_print_flags_buffer2(ap, var, s_flags);
	else
	{
		if (var->type == TYPE_ADDRESS)
			ft_flags_stock(var, s_flags,
						ft_lltoa_base(va_arg(ap, unsigned long), 16));
		else if (var->type == TYPE_HEXA)
			ft_conv_envoi(ap, var, s_flags, 16);
		else if (var->type == TYPE_HEXA_MAJ)
			ft_conv_envoi_maj(ap, var, s_flags, 16);
		else if (var->type == TYPE_OCTAL)
			ft_conv_envoi(ap, var, s_flags, 8);
		else if (var->type == TYPE_OCTAL_MAJ)
			ft_conv_envoi_maj(ap, var, s_flags, 8);
		else if (var->type == TYPE_BITWISE)
			ft_conv_envoi(ap, var, s_flags, 2);
		else
			ft_conv_envoi(ap, var, s_flags, 10);
	}
	return (1);
}
