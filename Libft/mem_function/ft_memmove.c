/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbardet <jbardet@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:48:50 by jbardet           #+#    #+#             */
/*   Updated: 2020/02/20 11:50:47 by jbardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*dest;
	const char		*srce;
	char			*srcetemp;
	char			*desttemp;

	srce = src;
	dest = dst;
	if (src == NULL && dst == NULL && len != 0)
		return (0);
	if (dest < srce)
	{
		while (len--)
			*dest++ = *srce++;
	}
	else
	{
		srcetemp = (char *)srce + (len - 1);
		desttemp = dest + (len - 1);
		while (len--)
			*desttemp-- = *srcetemp--;
	}
	return (dst);
}
