/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_largeur.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 16:06:54 by elbenkri          #+#    #+#             */
/*   Updated: 2018/01/09 06:39:41 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_flags_precision2(t_var *var, int i)
{
	while (i < (int)ft_strlen(var->buf_tmp))
		var->buf[var->i_buf++] = var->buf_tmp[i++];
	if (var->type == TYPE_CHAR && !var->nb.c && ft_strlen(var->buf_tmp))
		var->buf[var->i_buf - 1] = var->nb.c;
	else if (var->type == TYPE_CHAR && !var->nb.c && !ft_strlen(var->buf_tmp))
		var->buf[var->i_buf++] = var->nb.c;
}

void			ft_flags_precision(t_var *var, t_flags *s_flags, int i)
{
	ft_bzero(var->buf_tmp, 500);
	if (!s_flags->precision && ft_strchr(var->flags_stock, '.') &&
		var->type > TYPE_MODULO)
		var->res = 0;
	if (!s_flags->precision && var->res)
		s_flags->precision = (int)ft_strlen(var->res);
	var->i_buf_tmp = (s_flags->c & (1 << 2)) ?
		0 : s_flags->largeur - s_flags->precision;
	if (var->res)
		(var->i_buf_tmp < 0) ? ft_memcpy(&var->buf_tmp[0], var->res,
s_flags->precision) : ft_memcpy(&var->buf_tmp[var->i_buf_tmp],
var->res, s_flags->precision);
	if (!var->i_buf_tmp)
	{
		i = s_flags->precision;
		var->i_buf_tmp = s_flags->largeur;
	}
	while (i < var->i_buf_tmp)
	{
		if ((!(s_flags->c & (1 << 2))) && (s_flags->c & (1 << 0)))
			var->buf_tmp[i++] = '0';
		else
			var->buf_tmp[i++] = ' ';
	}
	ft_flags_precision2(var, 0);
}

static void		ft_flags_largeur2(t_var *var, t_flags *s_flags, int i)
{
	while (i < var->i_buf_tmp)
	{
		if ((!(s_flags->c & (1 << 2))) && (s_flags->c & (1 << 0)))
			var->buf_tmp[i++] = '0';
		else
			var->buf_tmp[i++] = ' ';
	}
	i = 0;
	while (i < (int)ft_strlen(var->buf_tmp))
		var->buf[var->i_buf++] = var->buf_tmp[i++];
	if (var->type == TYPE_CHAR && !var->nb.c && ft_strlen(var->buf_tmp))
		var->buf[var->i_buf - 1] = var->nb.c;
	else if (var->type == TYPE_CHAR && !var->nb.c && !ft_strlen(var->buf_tmp))
		var->buf[var->i_buf++] = var->nb.c;
}

void			ft_flags_largeur(t_var *var, t_flags *s_flags, int i)
{
	int			len;

	len = (int)ft_strlen(var->res);
	if (s_flags->largeur < len)
		var->i_buf_tmp = 0;
	else if (s_flags->precision >= len)
		var->i_buf_tmp = (s_flags->c & (1 << 2)) ? 0 :
			s_flags->largeur - len;
	else
		var->i_buf_tmp = (s_flags->c & (1 << 2)) ? 0 : s_flags->largeur;
	ft_memcpy(&var->buf_tmp[var->i_buf_tmp], var->res, len + 1);
	if (var->type == TYPE_NON_CONNU)
		ft_memcpy(&var->buf_tmp[var->i_buf_tmp], var->res, len);
	if (!var->i_buf_tmp)
	{
		i = len;
		var->i_buf_tmp = s_flags->largeur;
	}
	if (s_flags->precision < (int)ft_strlen(var->res))
		var->i_buf_tmp += len;
	ft_flags_largeur2(var, s_flags, i);
}
