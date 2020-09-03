/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbardet <jbardet@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:48:08 by jbardet           #+#    #+#             */
/*   Updated: 2020/02/20 11:49:27 by jbardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*list;
	t_list	*wtf;

	if (!lst || !f)
		return (NULL);
	if (!(temp = ft_lstnew((*f)(lst->content))))
		return (NULL);
	list = temp;
	wtf = lst->next;
	while (wtf)
	{
		if (!(temp->next = ft_lstnew((*f)(wtf->content))))
		{
			ft_lstclear(&list, (*del));
			return (NULL);
		}
		temp = temp->next;
		wtf = wtf->next;
	}
	return (list);
}
