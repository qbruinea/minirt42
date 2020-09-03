/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 17:20:32 by user42            #+#    #+#             */
/*   Updated: 2020/08/17 17:40:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int		check_xyz(char **coor, int i, int p_index, char is_vec)
{
    char **temp;

    temp = ft_split_cset(coor[p_index], ",", 0);
    while (ft_strisnum(temp[i]) == 1)
		i++;
    if (i != 3)
    {
        ft_free_split(coor, 0);
		ft_free_split(temp, 0);
		printf("Erreur coordonnée. Les coordonnées doivent être des chiffres et sous le format : 0.0,0.0,0.0\n");
		return (0);
    }
	if (is_vec == 'v')
	{
		i = 0;
		while (temp[i] && i <= 3)
		{
			if (ft_atod(temp[i]) < -1 || ft_atod(temp[i]) > 1)
			{
				ft_free_split(coor, 0);
				ft_free_split(temp, 0);
				printf("Erreur vecteur d'orientation. Le vecteur d'orientation doit être situé entre -1 et 1\n");
				return (0);
			}
			++i;
		}
	}
    ft_free_split(temp, 0);
    return (1);
}

int		check_diam_or_high(char **str, int p_index, char is_h_or_d)
{
	if ((ft_strisnum(str[p_index]) == 0) || ft_atod(str[p_index]) <= 0)
	{
		ft_free_split(str, 0);
		if (is_h_or_d == 'd')
			printf("Erreur diamètre. Il doit être supérieur à 0.");
		else if (is_h_or_d == 'h')
			printf("Erreur hauteur. Elle doit être supérieur à 0.");
		else
			printf("Erreur résolution. Elle doit être supérieur à 0.");
		return (0);
	}
	return (1);
}

int		check_rgb(char **rgb, int i, int p_index)
{
	char **temp;

	temp = ft_split_cset(rgb[p_index], ",", 0);
	while (ft_strisnum(temp[i]) == TRUE)
		++i;
	if (i != 3)
	{
		ft_free_split(rgb, 0);
		ft_free_split(temp, 0);
		printf("Bad RGB light");
		return (0);
	}
	i = 0;
	while (ft_strisnum(temp[i]) == 1)
	{
		if (ft_atoi(temp[i]) < 0 || ft_atoi(temp[i]) > 255)
		{
			printf("RGB < 0 ou > 255");
			ft_free_split(temp, 0);
			ft_free_split(rgb, 0);
			return (0);
		}
		++i;
	}
	ft_free_split(temp, 0);
	return (1);
}

int		check_lightrange(char **lrange, int i, int p_index)
{
	char	**temp;

	temp = ft_split_cset(lrange[p_index], ",", 0);
	while (ft_strisnum(temp[i]) == TRUE)
		i++;
	if (i != 1)
	{
		ft_free_split(lrange, 0);
		ft_free_split(temp, 0);
		printf("Bad ratio light");
		return (0);
	}
	
	if (ft_atod(temp[0]) > 1 || ft_atod(temp[0]) < 0)
	{
		ft_free_split(lrange, 0);
		ft_free_split(temp, 0);
		printf("Erreur lumière. Elle doit être situé entre 0 et 1.\n");
		return (0);
	}
	ft_free_split(temp, 0);
	return (1);
}

int		check_fov(char **fov, int p_index)
{
	if (ft_strisnum(fov[p_index]) == FALSE || (ft_atod(fov[p_index]) < 0 || ft_atod(fov[p_index]) > 180))
	{
		ft_free_split(fov, 0);
		printf("Erreur FOV. Il doit être constitué de chiffres/nombres dans une range de 0 à 180.\n");
		return(0);
	}
	return (1);
}