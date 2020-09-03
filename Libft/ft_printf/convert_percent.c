/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tcurinie <tcurinie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 11:30:10 by jbardet           #+#    #+#             */
/*   Updated: 2020/06/15 18:07:53 by Tcurinie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_percent(va_list my_list, char *o_flags, int *o_len)
{
	int		tmp;
	char	*str;
	void	*test;

	test = my_list;
	test++;
	tmp = 0;
	if (o_flags[0] == '\0')
		return ;
	str = fill_alloc('%', 1);
	if (ext_param(o_flags, '-') != -1)
		str = minus_nb(str, o_flags, 0);
	if (ext_width(o_flags) != -1 || ext_zero(o_flags) != -1)
	{
		tmp = ext_zero(o_flags) >= ext_width(o_flags) ?
				ext_zero(o_flags) : ext_width(o_flags);
		str = wi_nb(str, o_flags, tmp, ext_zero(o_flags));
	}
	if (!str)
		*o_len += 1;
	else
		*o_len += ft_strlen(str);
	ft_putstr(str);
	free(str);
}
