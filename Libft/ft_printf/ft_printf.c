/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tcurinie <tcurinie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:45:08 by jbardet           #+#    #+#             */
/*   Updated: 2020/06/09 16:37:50 by Tcurinie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		parse_percent(const char *src, t_print *base, va_list my_list)
{
	base->tmpindex = base->i;
	while (is_valid_type(src[base->i], "-0.*123456789") != -1)
		base->i++;
	if (is_valid_type(src[base->i], "cspdiuxX%") == -1)
		base->i--;
	base->flags = ft_substr(src, base->tmpindex, base->i - base->tmpindex + 1);
	base->flags = flags_formater(my_list, base->flags);
	base->tmpindex = findindex(base->tabindex, src[base->i]);
	if (base->tmpindex != -1)
		(base->tabfunction[base->tmpindex](my_list, base->flags, &base->len));
	if (base->tmpindex == 8 && src[base->i + 1])
	{
		base->i += 1;
		if (src[base->i] != '%' && src[base->i] != '\0')
		{
			write(1, &src[base->i], 1);
			base->len += 1;
		}
	}
	free(base->flags);
	return (base->i);
}

int		ft_printf(const char *src, ...)
{
	t_print	*base;
	va_list	my_list;
	int		size;

	base = malloc(sizeof(t_print));
	init_struct(base);
	va_start(my_list, src);
	base->i = 0;
	while (src[base->i])
	{
		if (base->i != 0 && src[base->i - 1] == '%')
			base->i = parse_percent(src, base, my_list);
		else if (src[base->i] != '%')
		{
			write(1, &src[base->i], 1);
			base->len += 1;
		}
		base->i++;
	}
	size = base->len;
	free(base);
	va_end(my_list);
	return (size);
}
