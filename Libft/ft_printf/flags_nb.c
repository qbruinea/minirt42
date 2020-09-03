/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tcurinie <tcurinie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:45:16 by jbardet           #+#    #+#             */
/*   Updated: 2020/06/09 16:37:50 by Tcurinie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		is_minus(char *o_flags, int j)
{
	while (o_flags[++j])
	{
		if (j >= 1 && o_flags[j] == '-' && o_flags[j - 1] == '.'
		&& o_flags[0] != '-')
			return (-1);
	}
	return (0);
}

char	*move_minus(char *str, int j)
{
	j = is_valid_type('-', str);
	if (j != -1)
		str[j] = '0';
	j = 0;
	while (str[j] != '0')
		j++;
	str[j] = '-';
	return (str);
}

char	*wi_nb(char *str, char *o_flags, int index, int zero)
{
	char	*temp;

	if ((int)ft_strlen(str) <= index)
	{
		if ((zero != -1 && ext_param(o_flags, '.') == -1))
			temp = fill_alloc('0', index - ft_strlen(str));
		else
			temp = fill_alloc(' ', index - ft_strlen(str));
		str = ft_strjoinfree(temp, str, str);
		free(temp);
	}
	return (str);
}

char	*pre_nb(char *str, char *o_flags, int index)
{
	char	*temp;

	index = ext_param(o_flags, '.');
	if ((int)ft_strlen(str) <= index)
	{
		if (ext_param(str, '-') != -1)
			temp = fill_alloc('0', index - ft_strlen(str) + 1);
		else
			temp = fill_alloc('0', index - ft_strlen(str));
		str = ft_strjoinfree(temp, str, str);
		free(temp);
	}
	if (str && str[0] == '0' && str[1] == 0 && index == 0)
		str[0] = 0;
	return (str);
}

char	*minus_nb(char *str, char *o_flags, int index)
{
	char	*temp;

	if (is_minus(o_flags, -1) == -1)
		return (str);
	index = ext_param(o_flags, '-');
	if ((int)ft_strlen(str) < index)
	{
		temp = fill_alloc(' ', index - ft_strlen(str));
		str = ft_strjoinfree(str, temp, str);
		free(temp);
	}
	if (str && str[0] == '0' && str[1] == 0 && index == 0)
		str[0] = 0;
	return (str);
}
