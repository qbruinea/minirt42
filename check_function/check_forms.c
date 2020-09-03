/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_forms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 22:56:07 by user42            #+#    #+#             */
/*   Updated: 2020/08/21 17:48:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int		check_sphere(char *line, t_minirt *base)
{
	char **strs;

	strs = ft_split_cset(line, whitespace, 0);
	if ((check_nb_param(strs, 0, 4) == 0) ||
		(check_xyz(strs, 0, 1, 'n') == 0) ||
		(check_diam_or_high(strs, 2, 'd') == 0) ||
		(check_rgb(strs, 0, 3) == 0))
		{
			base->count_error += 1;
			return (0);
		}
	ft_free_split(strs, 0);
	return (base->count_sp += 1);
}

int		check_plane(char *line, t_minirt *base)
{
	char **strs;
	
	strs = ft_split_cset(line, whitespace, 0);
	if ((check_nb_param(strs, 0, 4) == 0) ||
		(check_xyz(strs, 0, 1, 'n') == 0) ||
		(check_xyz(strs, 0, 2, 'v') == 0) ||
		(check_rgb(strs, 0, 3) == 0))
		{
			base->count_error += 1;
			return (0);
		}
	ft_free_split(strs, 0);
	return (base->count_pl += 1);
}

int		check_square(char *line, t_minirt *base)
{
	char **strs;

	strs = ft_split_cset(line, whitespace, 0);
	if ((check_nb_param(strs, 0, 5) == 0) ||
		(check_xyz(strs, 0, 1, 'n') == 0) ||
		(check_xyz(strs, 0, 2, 'v') == 0) ||
		(check_diam_or_high(strs, 3, 'h') == 0) ||
		(check_rgb(strs, 0, 4) == 0))
		{
			base->count_error += 1;
			return (0);
		}
	ft_free_split(strs, 0);
	return (base->count_sq += 1);
}

int		check_cyl(char *line, t_minirt *base)
{
	char **strs;

	strs = ft_split_cset(line, whitespace, 0);
	if ((check_nb_param(strs, 0, 6) == 0) ||
		(check_xyz(strs, 0, 1, 'n') == 0) ||
		(check_xyz(strs, 0, 2, 'v') == 0) ||
		(check_diam_or_high(strs, 3, 'd') == 0) ||
		(check_diam_or_high(strs, 4, 'h') == 0) ||
		(check_rgb(strs, 0, 5) == 0))
		{
			base->count_error += 1;
			return (0);
		}
	ft_free_split(strs, 0);
	return (base->count_cy += 1);
}

int		check_triangle(char *line, t_minirt *base)
{
	char **strs;

	strs = ft_split_cset(line, whitespace, 0);
	if ((check_nb_param(strs, 0, 5) == 0) ||
		(check_xyz(strs, 0, 1, 'n') == 0) ||
		(check_xyz(strs, 0, 2, 'n') == 0) ||
		(check_xyz(strs, 0, 3, 'n') == 0) ||
		(check_rgb(strs, 0, 4) == 0))
		{
			base->count_error += 1;
			return (0);
		}
	ft_free_split(strs, 0);
	return (base->count_tr += 1);
	
}