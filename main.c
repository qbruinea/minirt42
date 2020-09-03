/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 16:13:11 by user42            #+#    #+#             */
/*   Updated: 2020/09/01 18:28:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/miniRT.h"

int main (int argc, char **argv)
{
	t_minirt *base;
	t_fonction	*tab_func;

	if (argc < 2)
	{
		printf("ERROR : no description scene file");
		return(0);
	}
	if (argc > 3)
	{
		printf("ERROR : too many arguments");
		return(0);
	}

	base = malloc(sizeof(t_minirt));
	tab_func = malloc(sizeof(t_fonction));
	if (check_and_freete(base, tab_func, argv[1]) == -1)
		return (free_everything(base, tab_func, -1));
	get_and_freete(base, tab_func, argv[1]);

    if ((base->mlx.mlx = mlx_init()) == NULL)
        return (EXIT_FAILURE);
    if ((base->mlx.win = mlx_new_window(base->mlx.mlx, base->tab_res.x, base->tab_res.y, "Hello world")) == NULL)
        return (EXIT_FAILURE);
    mlx_loop(base->mlx.mlx);
    return (EXIT_SUCCESS);
	
	free_struct_tab(base);
	return (free_everything(base, tab_func, 0));
}
