/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 16:22:39 by Tcurinie          #+#    #+#             */
/*   Updated: 2020/08/06 17:26:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strisnum(char *str)
{
	unsigned int i;

	i = 0;
	if (!str)
		return (FALSE);
	if (str[i] == '-')
		i++;
	while (ft_isdigit(str[i]) || str[i] == '.')
		i++;
	if (ft_strlen(str) == i)
		return (TRUE);
	else
		return (FALSE);
}