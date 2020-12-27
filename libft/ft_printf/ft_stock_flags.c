/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 07:45:16 by elbenkri          #+#    #+#             */
/*   Updated: 2018/02/02 14:56:49 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_verif_conv(t_var *var, char c)
{
	if (c != 'l' && c != 'h' && c != 'z' && c != 'j' && c != '-' &&
		c != '+' && c != '0' && c != ' ' && c != '#' && c != '.' && c != '%'
		&& !ft_strchr(var->flags_conv, c))
	{
		if (!ft_isdigit(c))
		{
			var->nb.c = c;
			var->res = &c;
			return (1);
		}
	}
	return (0);
}

static int		ft_stock_flags2(char *str, t_var *var, int *i)
{
	if (!str[*i] || str[*i] == '%')
	{
		ft_type(var, '%');
		var->flags_stock[var->i_stock++] = str[*i];
		*i = *i + 1;
		var->flags_stock[var->i_stock] = 0;
		return (1);
	}
	return (0);
}

int				ft_stock_flags3(char *str, t_var *var, int *i)
{
	if (ft_verif_conv(var, str[*i]))
	{
		ft_type(var, 'N');
		if (!str[*i + 1])
			return (*i);
		else
		{
			*i = *i + 1;
			return (*i);
		}
	}
	return (0);
}

int				ft_stock_flags(char *str, t_var *var)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	var->i_stock = 0;
	while (str[i])
	{
		if (ft_strchr(var->flags_conv, str[i]))
			ft_type(var, str[i]);
		while (var->flags_conv[j] && var->flags_conv[j] != str[i])
			j++;
		if (var->flags_conv[j] == str[i])
			return (i + 1);
		j = 0;
		if (ft_stock_flags3(str, var, &i))
			return (i);
		var->flags_stock[var->i_stock++] = str[i++];
		var->flags_stock[var->i_stock] = 0;
		if (ft_stock_flags2(str, var, &i))
			return (i);
	}
	return (0);
}
