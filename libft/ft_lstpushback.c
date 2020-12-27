/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:14:37 by elbenkri          #+#    #+#             */
/*   Updated: 2017/11/13 17:24:45 by elbenkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **lst, t_list *elem)
{
	t_list	*tmp;

	tmp = *lst;
	if (!lst)
		return ;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = elem;
}
