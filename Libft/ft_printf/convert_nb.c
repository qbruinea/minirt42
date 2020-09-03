/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_nb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tcurinie <tcurinie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 11:29:36 by jbardet           #+#    #+#             */
/*   Updated: 2020/06/09 16:37:50 by Tcurinie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_nbr(va_list my_list, char *o_flags, int *o_len)
{
	int		nb;
	int		tmp;
	char	*str;

	nb = va_arg(my_list, int);
	str = ft_itoa(nb);
	if (ext_param(o_flags, '.') != -1 && is_minus(o_flags, -1) == 0)
		str = pre_nb(str, o_flags, 0);
	if (ext_width(o_flags) != -1 || ext_zero(o_flags) != -1)
	{
		tmp = ext_zero(o_flags) >= ext_width(o_flags) ?
			ext_zero(o_flags) : ext_width(o_flags);
		str = wi_nb(str, o_flags, tmp, ext_zero(o_flags));
	}
	if (ext_param(o_flags, '-') != -1 && is_minus(o_flags, -1) == 0)
		str = minus_nb(str, o_flags, 0);
	if (nb < 0)
		move_minus(str, 0);
	ft_putandfree(str, o_len);
}

void	ft_unsnbr(va_list my_list, char *o_flags, int *o_len)
{
	int				tmp;
	unsigned int	nb;
	char			*str;

	tmp = va_arg(my_list, int);
	if (tmp < 0)
		nb = UINT32_MAX - -tmp + 1;
	else
		nb = tmp;
	str = ft_utoa_base(nb, "0123456789");
	if (ext_param(o_flags, '.') != -1 && is_minus(o_flags, -1) == 0)
		str = pre_nb(str, o_flags, 0);
	if (ext_width(o_flags) != -1 || ext_zero(o_flags) != -1)
	{
		nb = ext_zero(o_flags) >= ext_width(o_flags) ?
				ext_zero(o_flags) : ext_width(o_flags);
		str = wi_nb(str, o_flags, nb, ext_zero(o_flags));
	}
	if (ext_param(o_flags, '-') != -1 && is_minus(o_flags, -1) == 0)
		str = minus_nb(str, o_flags, 0);
	ft_putandfree(str, o_len);
}

void	ft_hexa(va_list my_list, char *o_flags, int *o_len)
{
	int		nb;
	long	tmp;
	char	*str;

	nb = va_arg(my_list, unsigned long);
	tmp = nb;
	if (nb < 0)
		tmp = UINT32_MAX + 1 + nb;
	str = ft_utoa_base(tmp, "0123456789abcdef");
	if (ext_param(o_flags, '.') != -1 && is_minus(o_flags, -1) == 0)
		str = pre_nb(str, o_flags, 0);
	if (ext_width(o_flags) != -1 || ext_zero(o_flags) != -1)
	{
		nb = ext_zero(o_flags) >= ext_width(o_flags) ?
				ext_zero(o_flags) : ext_width(o_flags);
		str = wi_nb(str, o_flags, nb, ext_zero(o_flags));
	}
	if (ext_param(o_flags, '-') != -1 && is_minus(o_flags, -1) == 0)
		str = minus_nb(str, o_flags, 0);
	ft_putandfree(str, o_len);
}

void	ft_hexabig(va_list my_list, char *o_flags, int *o_len)
{
	int		nb;
	long	tmp;
	char	*str;

	nb = va_arg(my_list, unsigned long);
	tmp = nb;
	if (nb < 0)
		tmp = UINT32_MAX + 1 + nb;
	str = ft_utoa_base(tmp, "0123456789ABCDEF");
	if (ext_param(o_flags, '.') != -1 && is_minus(o_flags, -1) == 0)
		str = pre_nb(str, o_flags, 0);
	if (ext_width(o_flags) != -1 || ext_zero(o_flags) != -1)
	{
		nb = ext_zero(o_flags) >= ext_width(o_flags) ?
				ext_zero(o_flags) : ext_width(o_flags);
		str = wi_nb(str, o_flags, nb, ext_zero(o_flags));
	}
	if (ext_param(o_flags, '-') != -1 && is_minus(o_flags, -1) == 0)
		str = minus_nb(str, o_flags, 0);
	ft_putandfree(str, o_len);
}

void	ft_address(va_list my_list, char *o_flags, int *o_len)
{
	long	add;
	char	*str;
	char	*tmp;

	add = va_arg(my_list, long);
	str = fill_alloc('\0', 1);
	tmp = ft_strdup(str);
	free(str);
	if (add == 0 && ext_param(o_flags, '.') != -1)
	{
		str = ft_strjoinfree("0x", tmp, tmp);
		if (ext_width(o_flags) != -1)
			str = wi_nb(str, o_flags, ext_width(o_flags), -1);
		if (ext_param(o_flags, '-') != -1 && is_minus(o_flags, -1) == 0)
			str = minus_nb(str, o_flags, 0);
		ft_putandfree(str, o_len);
		return ;
	}
	free(tmp);
	tmp = ft_utoa_base(add, "0123456789abcdef");
	str = ft_strjoinfree("0x", tmp, tmp);
	str = wimin_adress(str, o_flags);
	ft_putandfree(str, o_len);
}
