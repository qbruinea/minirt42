/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbardet <jbardet@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:49:13 by jbardet           #+#    #+#             */
/*   Updated: 2020/02/20 11:51:03 by jbardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_isspace(int c)
{
	if ((c > 8 && c < 14) || (c == 32))
		return (TRUE);
	return (FALSE);
}

int			ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	neg;

	i = 0;
	neg = FALSE;
	nb = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			neg = TRUE;
	while (ft_isdigit(str[i]))
	{
		nb = nb * 10;
		nb = nb + (str[i] - '0');
		i++;
	}
	return (neg ? -nb : nb);
}
