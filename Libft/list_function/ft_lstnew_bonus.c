/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:48:12 by jbardet           #+#    #+#             */
/*   Updated: 2020/08/07 18:54:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	if (!(lst = (t_list*)malloc(sizeof(lst))))
		return (NULL);
	if (!content)
		lst->content = NULL;
	else
	{
		lst->content = content;
		lst->next = NULL;
		lst->prev = NULL;
	}
	return (lst);
}
