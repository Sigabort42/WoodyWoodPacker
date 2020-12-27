/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 05:21:28 by elbenkri          #+#    #+#             */
/*   Updated: 2017/11/13 06:59:57 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;

	if (lst == 0)
		return (0);
	tmp = f(lst);
	new = tmp;
	lst = lst->next;
	while (lst)
	{
		tmp->next = f(lst);
		tmp = tmp->next;
		lst = lst->next;
	}
	tmp = 0;
	return (new);
}
