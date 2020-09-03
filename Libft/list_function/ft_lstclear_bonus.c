/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbardet <jbardet@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:47:43 by jbardet           #+#    #+#             */
/*   Updated: 2020/02/20 11:49:04 by jbardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*begin;
	t_list	*list;

	begin = *lst;
	while (begin)
	{
		list = begin->next;
		ft_lstdelone(begin, del);
		begin = list;
	}
	*lst = 0;
}
