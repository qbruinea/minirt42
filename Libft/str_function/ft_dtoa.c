/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 14:55:07 by user42            #+#    #+#             */
/*   Updated: 2020/08/01 18:09:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		is_full(long double nb)
{
	if (nb == (double)((long long) nb))
		return (1);
	return (0);
}

char  *ft_dtoa(long double nb)
{
    double	nb_entier;
	double	nb_decimal;
	char	*str;
	int		i;

	i = 0;
	nb_entier = nb;
	str = ft_strjoin(ft_itoa(nb_entier), ".");
	nb_entier = ft_atoi(str);
	nb_decimal = nb - nb_entier;
	while (i++ != 6)
		nb_decimal *= 10;
	if (is_full(nb_decimal) == 0)
		nb_decimal += 1;
	str = ft_strjoin(str, ft_itoa(nb_decimal));
	return (str);
}
