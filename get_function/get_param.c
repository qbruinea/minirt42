/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 15:54:04 by user42            #+#    #+#             */
/*   Updated: 2020/08/15 16:52:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

t_coor	get_xyz(char **coor, int p_index)
{
	char	**temp;
	t_coor	struc_coor;

	temp = ft_split_cset(coor[p_index], ",", 0);
	struc_coor.x = ft_atod(temp[0]);
	struc_coor.y = ft_atod(temp[1]);
	struc_coor.z = ft_atod(temp[2]);
	ft_free_split(temp, 0);
	return(struc_coor);
}

t_color	get_rgb(char **rbg, int p_index)
{
	char	**temp;
	t_color	struc_color;

	temp = ft_split_cset(rbg[p_index], ",", 0);
	struc_color.r = ft_atoi(temp[0]);
	struc_color.g = ft_atoi(temp[1]);
	struc_color.b = ft_atoi(temp[2]);
	ft_free_split(temp, 0);
	return(struc_color);
}

t_vec3	get_vec_xyz(char **vcoor, int p_index)
{
	char	**temp;
	t_vec3	struc_vcoor;

	temp = ft_split_cset(vcoor[p_index], ",", 0);
	struc_vcoor.x = ft_atod(temp[0]);
	struc_vcoor.y = ft_atod(temp[1]);
	struc_vcoor.z = ft_atod(temp[2]);
	ft_free_split(temp, 0);
	return(struc_vcoor);
}
