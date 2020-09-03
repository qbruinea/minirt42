/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 22:28:34 by user42            #+#    #+#             */
/*   Updated: 2020/08/11 13:09:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void    get_res(char *line, t_minirt *base)
{
    char	**strs;

    strs = ft_split_cset(line, whitespace, 0);
    base->tab_res.x = ft_atoi(strs[1]);
	base->tab_res.y = ft_atoi(strs[2]);
	printf("check res good [%d][%d]\n", base->tab_res.x, base->tab_res.y);
    ft_free_split(strs, 0);
}

void    get_amb(char *line, t_minirt *base)
{
    char	**strs;

    strs = ft_split_cset(line, whitespace, 0);
    base->tab_amb.intensity = ft_atod(strs[1]);
	printf("amb intensity good [%f]\n", base->tab_amb.intensity);
	base->tab_amb.rgb = get_rgb(strs, 2);
	printf("amb rgb [%d][%d][%d]\n", base->tab_amb.rgb.r, base->tab_amb.rgb.g, base->tab_amb.rgb.b);
	ft_free_split(strs, 0);
}

void    get_cam(char *line, t_minirt *base)
{
    char	**strs;

	strs = ft_split_cset(line, whitespace, 0);
    base->tab_cam[base->count_cam - 1].coord = get_xyz(strs, 1);
	printf("check cam good [%f][%f][%f]\n", base->tab_cam[base->count_cam - 1].coord.x, base->tab_cam[base->count_cam - 1].coord.y, base->tab_cam[base->count_cam - 1].coord.z);
	base->tab_cam[base->count_cam - 1].vec_cam = get_vec_xyz(strs, 2);
	printf("check cam good [%f][%f][%f]\n", base->tab_cam[base->count_cam - 1].vec_cam.x, base->tab_cam[base->count_cam - 1].vec_cam.y, base->tab_cam[base->count_cam - 1].vec_cam.z);
	base->tab_cam[base->count_cam - 1].fov = ft_atod(strs[3]);
	printf("check cam good [%f]\n", base->tab_cam[base->count_cam - 1].fov);
	ft_free_split(strs, 0);
}

void    get_light(char *line, t_minirt *base)
{
    char	**strs;

	strs = ft_split_cset(line, whitespace, 0);
    base->tab_light->coord = get_xyz(strs, 1);
	printf("check light good [%f][%f][%f]\n", base->tab_light->coord.x, base->tab_light->coord.y, base->tab_light->coord.z);
	base->tab_light->intensity = ft_atod(strs[2]);
	printf("check light good [%f]\n", base->tab_light->intensity);
	base->tab_light->rgb = get_rgb(strs, 3);
	printf("check light good [%d][%d][%d]\n", base->tab_light->rgb.r, base->tab_light->rgb.g, base->tab_light->rgb.b);
	ft_free_split(strs, 0);
}