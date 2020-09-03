/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:37:02 by user42            #+#    #+#             */
/*   Updated: 2020/08/10 19:07:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	init_sphere(t_minirt *base)
{
	int	i;

	i = 0;
	base->tab_sp = malloc(sizeof(t_sphere) * base->count_sp);
	while (i < base->count_sp)
	{
		base->tab_sp[i].coord = set_xyz(0, 0, 0);
		base->tab_sp[i].rgb = set_rgb(0, 0, 0);
		base->tab_sp[i].diam = 0.0;
		i++;
	}
}

void	init_plane(t_minirt *base)
{
	int	i;

	i = 0;
	base->tab_pl = malloc(sizeof(t_plane) * base->count_pl);
	while (i < base->count_pl)
	{
		base->tab_pl[i].coord = set_xyz(0, 0, 0);
		base->tab_pl[i].vec = set_xyzvec(0, 0, 0);
		base->tab_pl[i].rgb = set_rgb(0, 0, 0);
		i++;
	}
	
}

void	init_square(t_minirt *base)
{
	int	i;

	i = 0;
	base->tab_sq = malloc(sizeof(t_square) * base->count_sq);
	while (i < base->count_sq)
	{
		base->tab_sq[i].coord = set_xyz(0, 0, 0);
		base->tab_sq[i].vec = set_xyzvec(0, 0, 0);
		base->tab_sq[i].height = 0.0;
		base->tab_sq[i].rgb = set_rgb(0, 0, 0);
		i++;
	}
	
}

void	init_cylinder(t_minirt *base)
{
	int	i;

	i = 0;
	base->tab_cyl = malloc(sizeof(t_cyl) * base->count_cy);
	while (i < base->count_cy)
	{
		base->tab_cyl[i].coord = set_xyz(0, 0, 0);
		base->tab_cyl[i].vec = set_xyzvec(0, 0, 0);
		base->tab_cyl[i].rgb = set_rgb(0, 0, 0);
		base->tab_cyl[i].diam = 0.0;
		base->tab_cyl[i].height = 0.0;
		i++;
	}
	
}

void	init_triangle(t_minirt *base)
{
	int	i;

	i = 0;
	base->tab_tr = malloc(sizeof(t_tria) * base->count_tr);
	while (i > base->count_tr)
	{
		base->tab_tr[i].coord_un = set_xyz(0, 0, 0);
		base->tab_tr[i].coord_dos = set_xyz(0, 0, 0);
		base->tab_tr[i].coord_tres = set_xyz(0, 0, 0);
		base->tab_tr[i].rgb = set_rgb(0, 0, 0);
		i++;
	}

}