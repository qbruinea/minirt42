/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 15:41:42 by user42            #+#    #+#             */
/*   Updated: 2020/08/09 21:50:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void    *ft_realloc(void *ptr, size_t new_size)
{
	char	*new_ptr;
	size_t	current_size;
	
	if (ptr == 0)
		return (malloc(new_size));
	current_size = sizeof(ptr);
	if (new_size <= current_size)
		return (ptr);
	new_ptr = malloc(new_size);
	ft_memcpy(ptr, new_ptr, current_size);
	free(ptr);
	return (new_ptr);
}