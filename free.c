/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 21:20:38 by user42            #+#    #+#             */
/*   Updated: 2020/08/14 17:43:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/miniRT.h"

void	free_struct_tab(t_minirt *base)
{
	if (base->count_cam > 0)
		free(base->tab_cam);
	if (base->count_light > 0)
		free(base->tab_light);
	if (base->count_sp > 0)
		free(base->tab_sp);
	if (base->count_pl > 0)
		free(base->tab_pl);
	if (base->count_sq > 0)
		free(base->tab_sq);
	if (base->count_cy > 0)
		free(base->tab_cyl);
	if (base->count_tr > 0)
		free(base->tab_tr);
}

int		free_everything(t_minirt *base, t_fonction *check_func, int retend)
{
	free(check_func);
	free(base);
	return (retend);
}
