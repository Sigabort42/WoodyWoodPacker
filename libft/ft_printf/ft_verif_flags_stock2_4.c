/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_flags_stock2_4.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 14:48:41 by elbenkri          #+#    #+#             */
/*   Updated: 2018/01/20 14:49:07 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_verif_flags_stock2_4(t_flags *s_flags, t_var *var)
{
	int	i;

	i = 0;
	if (s_flags->c & (1 << 3) && (var->type == TYPE_SHORT ||
		var->type == TYPE_INT || var->type == TYPE_SHORT_MAJ))
	{
		ft_memcpy(&var->buf_tmp[var->i_buf_tmp], " ", 1);
		var->i_buf_tmp += ++i;
	}
	return (i);
}
