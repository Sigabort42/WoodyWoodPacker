/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 16:24:38 by elbenkri          #+#    #+#             */
/*   Updated: 2018/01/11 23:22:11 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_wchar2(wchar_t chr, t_var *var, int i)
{
	if (chr > 0)
		var->i_buf -= i;
	if (chr <= 127)
		var->buf[var->i_buf++] = chr;
	else if (chr <= 2047)
	{
		var->buf[var->i_buf++] = (chr >> 6) + 192;
		var->buf[var->i_buf++] = (chr & 63) + 128;
	}
	else if (chr <= 65535)
	{
		var->buf[var->i_buf++] = (chr >> 12) + 224;
		var->buf[var->i_buf++] = ((chr >> 6) & 63) + 128;
		var->buf[var->i_buf++] = (chr & 63) + 128;
	}
	else if (chr <= 1114111)
	{
		var->buf[var->i_buf++] = (chr >> 18) + 240;
		var->buf[var->i_buf++] = ((chr >> 12) & 63) + 128;
		var->buf[var->i_buf++] = ((chr >> 6) & 63) + 128;
		var->buf[var->i_buf++] = (chr & 63) + 128;
	}
}

char		*ft_wchar(wchar_t chr)
{
	char	*c;

	c = ft_strnew(4);
	if (chr <= 127)
		c[0] = chr;
	else if (chr <= 2047)
	{
		c[0] = (chr >> 6) + 192;
		c[1] = (chr & 63) + 128;
	}
	else if (chr <= 65535)
	{
		c[0] = (chr >> 12) + 224;
		c[1] = ((chr >> 6) & 63) + 128;
		c[2] = (chr & 63) + 128;
	}
	else if (chr <= 1114111)
	{
		c[0] = (chr >> 18) + 240;
		c[1] = ((chr >> 12) & 63) + 128;
		c[2] = ((chr >> 6) & 63) + 128;
		c[3] = (chr & 63) + 128;
	}
	return (c);
}
