/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 17:56:31 by user42            #+#    #+#             */
/*   Updated: 2020/08/21 17:47:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	init_struct_check(t_fonction *check_func)
{
	char *str[9];
	int	i;

	str[0] = "R";
	str[1] = "A";
	str[2] = "c";
	str[3] = "l";
	str[4] = "pl";
	str[5] = "sp";
	str[6] = "sq";
	str[7] = "cy";
	str[8] = "tr";
	i = -1;
	check_func->index = 0;
	check_func->tabfunction[0] = check_res;
	check_func->tabfunction[1] = check_amb;
	check_func->tabfunction[2] = check_cam;
	check_func->tabfunction[3] = check_light;
	check_func->tabfunction[4] = check_plane;
	check_func->tabfunction[5] = check_sphere;
	check_func->tabfunction[6] = check_square;
	check_func->tabfunction[7] = check_cyl;
	check_func->tabfunction[8] = check_triangle;
	while (++i < 9)
		check_func->tabindex[i] = str[i];
	check_func->tabindex[9] = 0;
    check_func->index = 0;
}

void    init_struct_get(t_fonction *get_func)
{
    get_func->index = 0;
    get_func->tabfunction_get[0] = get_res;
    get_func->tabfunction_get[1] = get_amb;
    get_func->tabfunction_get[2] = get_cam;
    get_func->tabfunction_get[3] = get_light;
    get_func->tabfunction_get[4] = get_plane;
    get_func->tabfunction_get[5] = get_sphere;
    get_func->tabfunction_get[6] = get_square;
    get_func->tabfunction_get[7] = get_cyl;
    get_func->tabfunction_get[8] = get_triangle;
}

void	init_struct_cmp(t_minirt *base)
{
	base->count_res = 0;
	base->count_amb = 0;
	base->count_cam = 0;
	base->count_light = 0;
	base->count_sp = 0;
	base->count_pl = 0;
	base->count_sq = 0;
	base->count_cy = 0;
	base->count_tr = 0;
	base->count_error = 0;
}