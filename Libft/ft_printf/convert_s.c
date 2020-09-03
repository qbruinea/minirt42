/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tcurinie <tcurinie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:46:11 by jbardet           #+#    #+#             */
/*   Updated: 2020/06/09 16:37:50 by Tcurinie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*minus_str(char *str, char *o_flags, int minus)
{
	char	*temp;

	minus = ext_param(o_flags, '-');
	if (str == NULL)
	{
		free(str);
		str = fill_alloc(' ', minus);
	}
	else if (str != NULL && (int)ft_strlen(str) < minus)
	{
		temp = fill_alloc(' ', minus - ft_strlen(str));
		str = ft_strjoinfree(str, temp, str);
		free(temp);
	}
	return (str);
}

char	*wi_str(char *str, char *o_flags, int minus)
{
	char	*zero;

	zero = 0;
	minus = ext_width(o_flags);
	if (str == NULL)
	{
		free(str);
		str = fill_alloc(' ', minus);
	}
	else if (str != NULL && (int)ft_strlen(str) < minus)
	{
		zero = fill_alloc(' ', minus - ft_strlen(str));
		str = ft_strjoinfree(zero, str, str);
		free(zero);
	}
	return (str);
}

char	*pre_str(char *str, char *o_flags, int preci)
{
	char	*tmp;
	int		j;

	tmp = 0;
	j = 0;
	preci = ext_param(o_flags, '.');
	if (((int)ft_strlen(str) >= preci && preci != -1))
	{
		while (o_flags[++j])
		{
			if (j >= 1 && o_flags[j] == '-' && o_flags[j - 1] == '.'
			&& o_flags[0] == '-')
				return (str);
		}
		tmp = ft_substr(str, 0, preci);
		free(str);
		str = ft_strdup(tmp);
		free(tmp);
	}
	return (str);
}

void	ft_str(va_list my_list, char *o_flags, int *o_len)
{
	char	*str;
	char	*tmp;

	tmp = va_arg(my_list, char *);
	str = fill_alloc('\0', 1);
	if (tmp == NULL)
		str = ft_strjoinfree(str, "(null)", str);
	else
		str = ft_strjoinfree(str, tmp, str);
	if (ext_param(o_flags, '.') != -1 && is_minus(o_flags, -1) == 0)
		str = pre_str(str, o_flags, -1);
	if (ext_width(o_flags) != -1)
		str = wi_str(str, o_flags, -1);
	if (ext_param(o_flags, '-') != -1 && is_minus(o_flags, -1) == 0)
		str = minus_str(str, o_flags, -1);
	ft_putandfree(str, o_len);
}
