/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_view.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 15:35:28 by Tcurinie          #+#    #+#             */
/*   Updated: 2020/08/26 16:59:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int		check_nb_param(char **param, int i, int nb_param)
{
	while (param[i])
		++i;
	if (i != nb_param)
	{
		ft_free_split(param, 0);
		printf("Erreur paramètre. Veuillez vérifier si il y a le bon nombre de paramètres");
		return (0);
	}
	return (1);
}

int check_res(char *line, t_minirt *base)
{
	char	**strs;

	if (base->count_res == 1)
	{
		base->count_error += 1;
		printf("More than one res param !");
		return(0);
	}
	strs = ft_split_cset(line, whitespace, 0);
	if ((check_nb_param(strs, 0, 3) == 0) ||
		(check_diam_or_high(strs, 1, 'r') == 0) ||
		(check_diam_or_high(strs, 2, 'r') == 0))
		{
			base->count_error += 1;
			return (0);
		}
	ft_free_split(strs, 0);
	return(base->count_res = 1);
}

int check_amb(char *line, t_minirt *base)
{
	char	**strs;

	if (base->count_amb == 1)
	{
		base->count_error += 1;
		printf("More than one ambiant param !");
		return(0);
	}
	strs = ft_split_cset(line, whitespace, 0);
	
	if ((check_nb_param(strs, 0, 3) == 0) ||
		(check_lightrange(strs, 0, 1) == 0) ||
		(check_rgb(strs, 0, 2) == 0))
		{
			base->count_error += 1;
			return (0);
		}
	ft_free_split(strs, 0);
	return(base->count_amb = 1);
}

int	check_cam(char *line, t_minirt *base)
{
	char	**strs;

	strs = ft_split_cset(line, whitespace, 0);
	if ((check_nb_param(strs, 0, 4) == 0) ||
		(check_xyz(strs, 0, 1, 'n') == 0) ||
		(check_xyz(strs, 0, 2, 'v') == 0) ||
		(check_fov(strs, 3) == 0))
		{
			base->count_error += 1;
			return (0);
		}
	ft_free_split(strs, 0);
	return (base->count_cam += 1);
}

int		check_light(char *line, t_minirt *base)
{
	char	**strs;

	strs = ft_split_cset(line, whitespace, 0);
	if ((check_nb_param(strs, 0, 4) == 0) ||
		(check_xyz(strs, 0, 1, 'n') == 0) ||
		(check_lightrange(strs, 0, 2) == 0) ||
		(check_rgb(strs, 0, 3) == 0))
		{
			base->count_error += 1;
			return (0);
		}
	ft_free_split(strs, 0);
	return (base->count_light += 1);
}
