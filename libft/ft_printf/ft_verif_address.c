/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 14:48:14 by elbenkri          #+#    #+#             */
/*   Updated: 2018/01/20 14:48:16 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_verif_address(t_var *var)
{
	if (var->type == TYPE_ADDRESS)
	{
		ft_memcpy(&var->buf[var->i_buf], var->buf_tmp, var->i_buf_tmp);
		var->i_buf += var->i_buf_tmp;
		return (1);
	}
	return (0);
}
