/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 16:08:47 by Tcurinie          #+#    #+#             */
/*   Updated: 2020/07/22 15:34:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_isspace(int c)
{
	if ((c > 8 && c < 14) || (c == 32))
		return (TRUE);
	return (FALSE);
}

double    ft_atod(const char *s)
{
    double    res;
    double    coef;
    int        neg;

    while (ft_isspace(*s))
        s++;
    res = 0;
    neg = *s == '-' ? 1 : 0;
    if (*s == '+' || *s == '-')
        s++;
    while (ft_isdigit(*s))
        res = 10 * res + ((double)(*s++) - (double)'0');
    if (*s == '.')
    {
        coef = 10;
        s++;
        while (ft_isdigit(*s))
        {
            res += (*s++ - '0') / coef;
            coef *= 10;
        }
    }
    return (neg ? -res : res);
}