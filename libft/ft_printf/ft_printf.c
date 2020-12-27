/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:56:55 by elbenkri          #+#    #+#             */
/*   Updated: 2018/02/02 16:53:15 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const t_color	g_color[] =
{
	{"clear", "\033[H\033[2J"},
	{"{red}", "\033[31m"},
	{"{green}", "\033[32m"},
	{"{yellow}", "\033[33m"},
	{"{blue}", "\033[34m"},
	{"{magenta}", "\033[35m"},
	{"{cyan}", "\033[36m"},
	{NULL, NULL}
};

static int			ft_color(const char *format, t_var *var)
{
	const char		*reset_color = "\033[0m";
	int				i;

	i = -1;
	if (ft_strnequ("{eoc}", &format[0], 5))
	{
		ft_memcpy(&var->buf[var->i_buf], reset_color,
			var->i_buf += ft_strlen(reset_color));
		var->ret += 5;
	}
	if (ft_strstr(format, "{eoc}"))
	{
		while (g_color[++i].color)
		{
			if (ft_strnequ(g_color[i].color, &format[0],
						ft_strlen(g_color[i].color)))
			{
				ft_memcpy(&var->buf[var->i_buf], g_color[i].unicode,
					var->i_buf += ft_strlen(g_color[i].unicode));
				var->ret += ft_strlen(g_color[i].color);
				return (0);
			}
		}
	}
	return (0);
}

static int			ft_fd(const char *format, t_var *var)
{
	static int		i = 0;

	if (ft_strnequ("{fd}", &format[0], 4))
	{
		if (format[4] >= '0' && format[4] <= '9')
		{
			var->ret += 6;
			i = 1;
			var->fd = ft_atoi(&format[4]);
		}
		else
			var->ret += 5;
	}
	else if (i == 0)
		var->fd = 1;
	return (0);
}

static void			ft_verif(t_var *var)
{
	if (!ft_strcmp(var->buf, "cCdDioOuUxXpsSb") && var->i_buf == 15)
	{
		var->buf[0] = 0;
		var->i_buf = 0;
	}
}

int					ft_printf2(const char *format, va_list ap, t_var *var)
{
	t_flags			s_flags;

	s_flags.c = 0;
	while (format[var->ret])
	{
		while (!ft_color(&format[var->ret], var) &&
				!ft_fd(&format[var->ret], var) &&
		format[var->ret] && format[var->ret] != '%' && var->i_buf <= 10000)
			var->buf[var->i_buf++] = format[var->ret++];
		ft_verif_buf(var, format);
		if (!ft_strlen(var->flags_stock))
			break ;
		if ((var->type == TYPE_WSTRING || var->type == TYPE_WCHAR) &&
			MB_CUR_MAX <= 1)
			return (-1);
		(!ft_flags(&var->flags_stock[1], &s_flags)) ? ft_print_buffer(ap, var) :
			ft_print_flags_buffer(ap, var, &s_flags);
		var->nb_conv++;
		if (var->nb.u_i > 1114111 && var->type == TYPE_WCHAR)
			break ;
		ft_bzero(var->nb.str, 8);
		var->flags_stock[0] = 0;
	}
	ft_verif(var);
	return (0);
}

int					ft_printf(const char *format, ...)
{
	t_var			var;
	va_list			ap;

	ft_init_var(&var);
	va_start(ap, format);
	if (ft_return_printf2(format, ap, &var))
		return (-1);
	if (ft_verif_wchar_nb(&var))
		return (-1);
	else if (var.type == TYPE_WCHAR && var.nb_conv && var.nb.u_i > 1114111)
	{
		var.ret = var.ret - 1 - ft_strlen(var.flags_stock) - 1;
		while (format[var.ret--] != '%')
			var.i_buf--;
		var.i_buf++;
		write(var.fd, var.buf, var.i_buf);
		ft_free(&var);
		return (-1);
	}
	va_end(ap);
	write(var.fd, var.buf, var.i_buf);
	ft_free(&var);
	return (var.i_buf);
}
