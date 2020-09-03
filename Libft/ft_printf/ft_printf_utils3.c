/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tcurinie <tcurinie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:44:51 by jbardet           #+#    #+#             */
/*   Updated: 2020/06/09 16:37:50 by Tcurinie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_idontknow(char *o_flags, int j)
{
	if (is_valid_type('%', o_flags))
	{
		while (o_flags[j] == '-' || o_flags[j] == '0')
			++j;
	}
	else
	{
		while (o_flags[j] == '-')
			++j;
	}
	--j;
	return (j);
}

char	*wimin_adress(char *str, char *o_flags)
{
	if (ext_param(o_flags, '-') != -1 && is_minus(o_flags, -1) == 0)
		str = minus_nb(str, o_flags, 0);
	if (ext_width(o_flags) != -1)
		str = wi_nb(str, o_flags, ext_width(o_flags), -1);
	return (str);
}
