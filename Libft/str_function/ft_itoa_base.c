/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbardet <jbardet@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:49:36 by jbardet           #+#    #+#             */
/*   Updated: 2020/02/20 11:51:18 by jbardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_countnb(int n, int set)
{
	long	nbr;
	int		len;

	nbr = n;
	len = 0;
	if (nbr < 0)
	{
		len++;
		nbr = -nbr;
	}
	while (nbr >= set)
	{
		nbr = nbr / set;
		len++;
	}
	len++;
	return (len);
}

char		*ft_itoa_base(int n, char *set)
{
	int		size;
	char	*str;
	long	nbr;
	int		base;

	nbr = n;
	size = ft_countnb(n, ft_strlen(set));
	if (!(str = (char *)ft_calloc(sizeof(char), size + 1)))
		return (NULL);
	base = ft_strlen(set);
	if (nbr < 0)
	{
		nbr = -nbr;
		str[0] = '-';
	}
	--size;
	while (nbr >= base)
	{
		str[size--] = set[nbr % base];
		nbr = nbr / base;
	}
	str[size] = set[nbr];
	return (str);
}
