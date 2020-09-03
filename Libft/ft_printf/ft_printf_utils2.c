/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tcurinie <tcurinie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:46:26 by jbardet           #+#    #+#             */
/*   Updated: 2020/06/09 16:37:50 by Tcurinie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	init_struct(t_print *base)
{
	char	*str;
	int		j;

	str = "cspdiuxX%";
	base->len = 0;
	base->i = 0;
	j = -1;
	base->tmpindex = 0;
	base->tabfunction[0] = ft_char;
	base->tabfunction[1] = ft_str;
	base->tabfunction[2] = ft_address;
	base->tabfunction[3] = ft_nbr;
	base->tabfunction[4] = ft_nbr;
	base->tabfunction[5] = ft_unsnbr;
	base->tabfunction[6] = ft_hexa;
	base->tabfunction[7] = ft_hexabig;
	base->tabfunction[8] = ft_percent;
	while (++j < 9)
		base->tabindex[j] = str[j];
	base->tabindex[9] = 0;
}

int		ext_param(char *o_flags, char type)
{
	int		start;
	int		j;
	char	*tmp;

	j = -1;
	while (o_flags[++j])
	{
		if (o_flags[j] == type)
		{
			if (type == '-')
				j = ft_idontknow(o_flags, j);
			start = ++j;
			while (is_valid_type(o_flags[j], "0123456789") != -1)
				++j;
			tmp = ft_substr(o_flags, start, j - start);
			start = ft_atoi(tmp);
			free(tmp);
			return (start);
		}
	}
	return (-1);
}

int		ext_width(char *o_flags)
{
	int		start;
	int		j;
	char	*tmp;

	j = 0;
	if (is_valid_type(o_flags[0], "123456789") != -1)
	{
		start = 0;
		while (is_valid_type(o_flags[j], "0123456789") != -1)
			++j;
		tmp = ft_substr(o_flags, start, j - start);
		start = ft_atoi(tmp);
		free(tmp);
		return (start);
	}
	return (-1);
}

int		ext_zero(char *o_flags)
{
	int		start;
	int		j;
	char	*tmp;

	j = 0;
	if (is_valid_type(o_flags[0], "0") != -1)
	{
		start = 0;
		while (is_valid_type(o_flags[j], "0123456789") != -1)
			++j;
		tmp = ft_substr(o_flags, start, j - start);
		start = ft_atoi(tmp);
		free(tmp);
		return (start);
	}
	return (-1);
}

void	ft_putandfree(char *str, int *o_len)
{
	*o_len += ft_strlen(str);
	ft_putstr(str);
	free(str);
}
