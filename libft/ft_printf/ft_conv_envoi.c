/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_envoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 16:24:05 by elbenkri          #+#    #+#             */
/*   Updated: 2018/01/18 15:21:33 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_envoi3(va_list ap, t_var *var, t_flags *s_flags, int base)
{
	if ((s_flags->m & (1 << 5)) && (var->type >= TYPE_UNSIGNED &&
					var->type <= TYPE_HEXA_MAJ))
		ft_flags_stock(var, s_flags,
			ft_ui_maxtoa_base(va_arg(ap, ssize_t), base));
	else if ((s_flags->m & (1 << 5)))
		ft_flags_stock(var, s_flags,
			ft_ltoa_base(va_arg(ap, ssize_t), base));
	else
	{
		if (var->type <= TYPE_INT && s_flags->m == 0)
			ft_flags_stock(var, s_flags,
				ft_itoa_base(va_arg(ap, int), base));
		else
			ft_flags_stock(var, s_flags,
				ft_lltoa_base(va_arg(ap, unsigned int), base));
	}
}

void	ft_conv_envoi2(va_list ap, t_var *var, t_flags *s_flags, int base)
{
	if ((s_flags->m & (1 << 1)))
		ft_flags_stock(var, s_flags, ft_itoa_base((short)va_arg(ap, int),
							base));
	else if ((s_flags->m & (1 << 2)) && (var->type >= TYPE_UNSIGNED &&
					var->type <= TYPE_HEXA_MAJ))
		ft_flags_stock(var, s_flags, ft_lltoa_base(va_arg(ap, long long),
						base));
	else if ((s_flags->m & (1 << 2)))
		ft_flags_stock(var, s_flags, ft_ltoa_base(va_arg(ap, long long),
						base));
	else if ((s_flags->m & (1 << 4)) && (var->type >= TYPE_UNSIGNED &&
						var->type <= TYPE_HEXA_MAJ))
		ft_flags_stock(var, s_flags, ft_ui_maxtoa_base(va_arg(ap, uintmax_t),
						base));
	else if ((s_flags->m & (1 << 4)))
		ft_flags_stock(var, s_flags, ft_i_maxtoa_base(va_arg(ap, intmax_t),
						base));
	else
		ft_conv_envoi3(ap, var, s_flags, base);
}

void	ft_conv_envoi(va_list ap, t_var *var, t_flags *s_flags, int base)
{
	if (var->type == TYPE_UNSIGNED_MAJ || var->type == TYPE_OCTAL_MAJ ||
			var->type == TYPE_BITWISE)
		ft_flags_stock(var, s_flags, ft_lltoa_base(va_arg(ap, unsigned long),
						base));
	else if ((s_flags->m & (1 << 3)) &&
	((var->type >= TYPE_OCTAL && var->type <= TYPE_HEXA_MAJ) ||
			var->type == TYPE_UNSIGNED))
		ft_flags_stock(var, s_flags,
			ft_lltoa_base(va_arg(ap, unsigned long long), base));
	else if ((s_flags->m & (1 << 3)) || var->type == TYPE_SHORT_MAJ)
		ft_flags_stock(var, s_flags, ft_ltoa_base(va_arg(ap, long long), base));
	else if ((s_flags->m & (1 << 0)) && (var->type >= TYPE_UNSIGNED &&
			var->type <= TYPE_HEXA_MAJ))
		ft_flags_stock(var, s_flags,
		ft_itoa_base((unsigned char)va_arg(ap, int), base));
	else if ((s_flags->m & (1 << 0)))
		ft_flags_stock(var, s_flags, ft_itoa_base((char)va_arg(ap, int), base));
	else if ((s_flags->m & (1 << 1)) && (var->type >= TYPE_UNSIGNED &&
			var->type <= TYPE_HEXA_MAJ))
		ft_flags_stock(var, s_flags,
			ft_itoa_base((unsigned short)va_arg(ap, int), base));
	else
		ft_conv_envoi2(ap, var, s_flags, base);
}
