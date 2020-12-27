/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 06:38:32 by elbenkri          #+#    #+#             */
/*   Updated: 2017/11/13 07:15:28 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_appelle(int nb)
{
	if (nb < 10)
	{
		ft_putchar(nb + 48);
	}
	else
	{
		ft_appelle(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
}

void		ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			ft_appelle(214748364);
			ft_putchar('8');
		}
		else
			ft_appelle(-nb);
	}
	else
	{
		ft_appelle(nb);
	}
}
