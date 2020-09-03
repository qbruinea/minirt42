/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 19:09:53 by user42            #+#    #+#             */
/*   Updated: 2020/08/26 16:59:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	init_forms_and_views(t_minirt *base)
{
	init_res(base);
	init_amb(base);
	if (base->count_cam != 0)
		init_cam(base);
	if (base->count_light != 0)
		init_light(base);
	if (base->count_sp != 0)
		init_sphere(base);
	if (base->count_pl != 0)
		init_plane(base);
	if (base->count_sq != 0)
		init_square(base);
	if (base->count_cy != 0)
		init_cylinder(base);
	if (base->count_tr != 0)
		init_triangle(base);
}

void	init_res(t_minirt *base)
{
	base->tab_res.x = 0;
	base->tab_res.y = 0;
}

void	init_amb(t_minirt *base)
{
	base->tab_amb.intensity = 0.0;
	base->tab_amb.rgb = set_rgb(0, 0, 0);
}

void	init_cam(t_minirt *base)
{
	int i;

	i = 0;
	base->tab_cam = malloc(sizeof(t_cam) * base->count_cam);
	while (i < base->count_cam)
	{
		base->tab_cam[i].coord = set_xyz(0, 0, 0);
		base->tab_cam[i].vec_cam = set_xyzvec(0, 0, 0);
		base->tab_cam[i].fov = 0.0;
		i++;
	}
}

void	init_light(t_minirt *base)
{
	int	i;

	i = 0;
	base->tab_light = malloc(sizeof(t_light) * base->count_light);
	while (i < base->count_light)
	{
		base->tab_light[i].coord = set_xyz(0, 0, 0);
		base->tab_light[i].rgb = set_rgb(0, 0, 0);
		base->tab_light[i].intensity = 0.0;
		i++;
	}
}