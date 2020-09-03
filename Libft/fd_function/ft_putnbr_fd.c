/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbardet <jbardet@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:47:26 by jbardet           #+#    #+#             */
/*   Updated: 2020/02/20 11:35:31 by jbardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long q;

	q = n;
	if (q < 0)
	{
		ft_putchar_fd('-', fd);
		q = -q;
	}
	if (q < 10)
		ft_putchar_fd(q + '0', fd);
	else
	{
		ft_putnbr_fd(q / 10, fd);
		ft_putnbr_fd(q % 10, fd);
	}
}
