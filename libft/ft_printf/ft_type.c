/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 07:43:17 by elbenkri          #+#    #+#             */
/*   Updated: 2018/01/11 23:16:23 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type2(t_var *var, char c)
{
	if (c == 'o')
		var->type = TYPE_OCTAL;
	else if (c == 'O')
		var->type = TYPE_OCTAL_MAJ;
	else if (c == 'u')
		var->type = TYPE_UNSIGNED;
	else if (c == 'U')
		var->type = TYPE_UNSIGNED_MAJ;
	else if (c == '%')
		var->type = TYPE_MODULO;
	else if (c == 'b')
		var->type = TYPE_BITWISE;
	else if (c == 'S')
		var->type = TYPE_WSTRING;
	else if (c == 'N')
		var->type = TYPE_NON_CONNU;
}

void	ft_type(t_var *var, char c)
{
	if (c == 'c')
		var->type = TYPE_CHAR;
	else if (c == 'C')
		var->type = TYPE_WCHAR;
	else if (c == 'd')
		var->type = TYPE_SHORT;
	else if (c == 'D')
		var->type = TYPE_SHORT_MAJ;
	else if (c == 'i')
		var->type = TYPE_INT;
	else if (c == 's')
		var->type = TYPE_STRING;
	else if (c == 'x')
		var->type = TYPE_HEXA;
	else if (c == 'X')
		var->type = TYPE_HEXA_MAJ;
	else if (c == 'p')
		var->type = TYPE_ADDRESS;
	else
		ft_type2(var, c);
}
