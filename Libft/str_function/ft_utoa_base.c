/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbardet <jbardet@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:54:33 by jbardet           #+#    #+#             */
/*   Updated: 2020/02/20 11:53:24 by jbardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

static int	ft_countnb(unsigned long n, size_t set)
{
	unsigned long		nbr;
	size_t				len;

	nbr = n;
	len = 0;
	while (nbr >= set)
	{
		nbr = nbr / set;
		len++;
	}
	len++;
	return (len);
}

char		*ft_utoa_base(unsigned long n, char *set)
{
	int				size;
	char			*str;
	unsigned long	nbr;
	size_t			base;

	nbr = n;
	size = ft_countnb(nbr, ft_strlen(set));
	if (!(str = (char *)ft_calloc(sizeof(char), size + 1)))
		return (NULL);
	base = ft_strlen(set);
	--size;
	while (nbr >= base && size >= 0)
	{
		str[size--] = set[nbr % base];
		nbr = nbr / base;
	}
	str[size] = set[nbr];
	return (str);
}
