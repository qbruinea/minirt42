/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tcurinie <tcurinie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 11:27:11 by jbardet           #+#    #+#             */
/*   Updated: 2020/06/09 16:37:50 by Tcurinie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char		*minus_c(char *str, char *o_flags, int preci)
{
	char	*zero;

	zero = NULL;
	preci = ext_param(o_flags, '-');
	if (preci == 0 || preci == 1)
		return (str);
	if (!str[0])
	{
		zero = fill_alloc(' ', preci);
		free(str);
		str = ft_strdup(zero);
		free(zero);
		return (str);
	}
	if ((int)ft_strlen(str) < preci)
	{
		zero = fill_alloc(' ', preci - ft_strlen(str));
		str = ft_strjoinfree(str, zero, str);
		free(zero);
	}
	return (str);
}

char		*wi_c(char *str, char *o_flags, int preci)
{
	char	*zero;

	preci = ext_width(o_flags);
	if ((int)ft_strlen(str) < preci)
	{
		zero = fill_alloc(' ', preci - ft_strlen(str));
		if (str[0] == 0)
			zero[preci - 1] = '\0';
		else
			zero[preci - ft_strlen(str)] = '\0';
		str = ft_strjoinfree(zero, str, str);
		free(zero);
	}
	return (str);
}

static void	ft_putzero(char *str, int *o_len)
{
	ft_putchar('\0');
	write(1, str, ft_strlen(str) - 1);
	*o_len += 1 + ft_strlen(str) - 1;
	free(str);
}

static void	ft_writepoop(int k, int *o_len, char *str)
{
	while ((size_t)k <= ft_strlen(str))
		write(1, &str[k++], 1);
	*o_len += 1;
}

void		ft_char(va_list my_list, char *o_flags, int *o_len)
{
	int			c;
	char		*str;
	size_t		k;

	c = va_arg(my_list, int);
	str = fill_alloc(c, 1);
	if (ext_param(o_flags, '-') != -1 && is_minus(o_flags, -1) == 0)
		str = minus_c(str, o_flags, 0);
	if (c == 0 && str[0] == ' ')
	{
		ft_putzero(str, o_len);
		return ;
	}
	if (ext_width(o_flags) != -1)
		str = wi_c(str, o_flags, 0);
	*o_len += ft_strlen(str);
	k = 0;
	if (c == 0)
		ft_writepoop(k, o_len, str);
	else
		ft_putstr(str);
	free(str);
}
