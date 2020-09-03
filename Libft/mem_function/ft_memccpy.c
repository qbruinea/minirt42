/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbardet <jbardet@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:48:27 by jbardet           #+#    #+#             */
/*   Updated: 2020/02/20 11:50:16 by jbardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*srce;

	if (src == NULL && dst == NULL && n != 0)
		return (NULL);
	dest = (unsigned char *)dst;
	srce = (unsigned char *)src;
	i = 0;
	while (srce[i] != (unsigned char)c && i < n)
	{
		dest[i] = srce[i];
		i++;
	}
	if (srce[i] == (unsigned char)c)
	{
		dest[i] = srce[i];
		return (dst + i + 1);
	}
	return (NULL);
}
