/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_forms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 22:30:11 by user42            #+#    #+#             */
/*   Updated: 2020/08/11 15:36:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	get_sphere(char *line, t_minirt *base)
{
    char **strs;
	
	strs = ft_split_cset(line, whitespace, 0);
	printf("count [%d]\n", base->count_sp);
	base->tab_sp[base->count_sp - 1].coord = get_xyz(strs, 1);
	printf("check sphere good [%f][%f][%f]\n", base->tab_sp[base->count_sp - 1].coord.x, base->tab_sp[base->count_sp - 1].coord.y, base->tab_sp[base->count_sp - 1].coord.z);
	printf("check sphere good [%f][%f][%f]\n", base->tab_sp[0].coord.x, base->tab_sp[0].coord.y, base->tab_sp[0].coord.z);
	base->tab_sp[base->count_sp - 1].diam = ft_atod(strs[2]);
	printf("check sphere good [%f]\n", base->tab_sp[base->count_sp - 1].diam);
	printf("check sphere good [%f]\n", base->tab_sp[0].diam);
	base->tab_sp[base->count_sp - 1].rgb = get_rgb(strs, 3);
	printf("check sphere good [%d][%d][%d]\n", base->tab_sp[base->count_sp - 1].rgb.r, base->tab_sp[base->count_sp - 1].rgb.g, base->tab_sp[base->count_sp - 1].rgb.b);
	printf("check sphere good [%d][%d][%d]\n", base->tab_sp[0].rgb.r, base->tab_sp[0].rgb.g, base->tab_sp[0].rgb.b);
	ft_free_split(strs, 0);
}

void	get_plane(char *line, t_minirt *base)
{
	char **strs;
	
	strs = ft_split_cset(line, whitespace, 0);
	base->tab_pl[base->count_pl - 1].coord = get_xyz(strs, 1);
	printf("check plane good [%f][%f][%f]\n", base->tab_pl[base->count_pl - 1].coord.x, base->tab_pl[base->count_pl - 1].coord.y, base->tab_pl[base->count_pl - 1].coord.z);
	base->tab_pl[base->count_pl - 1].vec = get_vec_xyz(strs, 2);
	printf("check plane good [%f][%f][%f]\n", base->tab_pl[base->count_pl - 1].vec.x, base->tab_pl[base->count_pl - 1].vec.y, base->tab_pl[base->count_pl - 1].vec.z);
	base->tab_pl[base->count_pl - 1].rgb = get_rgb(strs, 3);
	printf("check plane good [%d][%d][%d]\n", base->tab_pl[base->count_pl - 1].rgb.r, base->tab_pl[base->count_pl - 1].rgb.g, base->tab_pl[base->count_pl - 1].rgb.b);
	ft_free_split(strs, 0);
}

void	get_square(char *line, t_minirt *base)
{
	char **strs;

	strs = ft_split_cset(line, whitespace, 0);
	base->tab_sq[base->count_sq - 1].coord = get_xyz(strs, 1);
	printf("check square good [%f][%f][%f]\n", base->tab_sq[base->count_sq - 1].coord.x, base->tab_sq[base->count_sq - 1].coord.y, base->tab_sq[base->count_sq - 1].coord.z);
	base->tab_sq[base->count_sq - 1].vec = get_vec_xyz(strs, 2);
	printf("check square good [%f][%f][%f]\n", base->tab_sq[base->count_sq - 1].vec.x, base->tab_sq[base->count_sq - 1].vec.y, base->tab_sq[base->count_sq - 1].vec.z);
	base->tab_sq[base->count_sq - 1].height = ft_atod(strs[3]);
	printf("check square good [%f]\n", base->tab_sq[base->count_sq - 1].height);
	base->tab_sq[base->count_sq - 1].rgb = get_rgb(strs, 4);
	printf("check square good [%d][%d][%d]\n", base->tab_sq[base->count_sq - 1].rgb.r, base->tab_sq[base->count_sq - 1].rgb.g, base->tab_sq[base->count_sq - 1].rgb.b);
	ft_free_split(strs, 0);
}

void	get_cyl(char *line, t_minirt *base)
{
	char **strs;

	strs = ft_split_cset(line, whitespace, 0);
	base->tab_cyl[base->count_cy - 1].coord = get_xyz(strs, 1);
	printf("check cyl good [%f][%f][%f]\n", base->tab_cyl[base->count_cy - 1].coord.x, base->tab_cyl[base->count_cy - 1].coord.y, base->tab_cyl[base->count_cy - 1].coord.z);
	base->tab_cyl[base->count_cy - 1].vec = get_vec_xyz(strs, 2);
	printf("check cyl good [%f][%f][%f]\n", base->tab_cyl[base->count_cy - 1].vec.x, base->tab_cyl[base->count_cy - 1].vec.y, base->tab_cyl[base->count_cy - 1].vec.z);
	base->tab_cyl[base->count_cy - 1].diam = ft_atod(strs[3]);
	printf("check cyl good [%f]\n", base->tab_cyl[base->count_cy - 1].diam);
	base->tab_cyl[base->count_cy - 1].height = ft_atod(strs[4]);
	printf("check cyl good [%f]\n", base->tab_cyl[base->count_cy - 1].height);
	base->tab_cyl[base->count_cy - 1].rgb = get_rgb(strs, 5);
	printf("check cyl good [%d][%d][%d]\n", base->tab_cyl[base->count_cy - 1].rgb.r, base->tab_cyl[base->count_cy - 1].rgb.g, base->tab_cyl[base->count_cy - 1].rgb.b);
	ft_free_split(strs, 0);
}

void	get_triangle(char *line, t_minirt *base)
{
	char **strs;

	strs = ft_split_cset(line, whitespace, 0);
	base->tab_tr[base->count_tr - 1].coord_un = get_xyz(strs, 1);
	printf("check triangle good [%f][%f][%f]\n", base->tab_tr[base->count_tr - 1].coord_un.x, base->tab_tr[base->count_tr - 1].coord_un.y, base->tab_tr[base->count_tr - 1].coord_un.z);
	base->tab_tr[base->count_tr - 1].coord_dos = get_xyz(strs, 2);
	printf("check triangle good [%f][%f][%f]\n", base->tab_tr[base->count_tr - 1].coord_dos.x, base->tab_tr[base->count_tr - 1].coord_dos.y, base->tab_tr[base->count_tr - 1].coord_dos.z);
	base->tab_tr[base->count_tr - 1].coord_tres = get_xyz(strs, 3);
	printf("check triangle good [%f][%f][%f]\n", base->tab_tr[base->count_tr - 1].coord_tres.x, base->tab_tr[base->count_tr - 1].coord_tres.y, base->tab_tr[base->count_tr - 1].coord_tres.z);
	base->tab_tr[base->count_tr - 1].rgb = get_rgb(strs, 4);
	printf("check triangle good [%d][%d][%d]\n", base->tab_tr[base->count_tr - 1].rgb.r, base->tab_tr[base->count_tr - 1].rgb.g, base->tab_tr[base->count_tr - 1].rgb.b);
	ft_free_split(strs, 0);
}