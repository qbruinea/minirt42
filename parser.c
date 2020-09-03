/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 16:13:28 by Tcurinie          #+#    #+#             */
/*   Updated: 2020/08/21 18:12:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/miniRT.h"

int		find_index(char **tab, char *element)
{
	int 	index;
	char	**strs;

	index = 0;
	strs = ft_split_cset(element, whitespace, 0);
	while (tab[index] != 0)
	{
		
		if (ft_strncmp(tab[index], strs[0], 9) == 0)
		{
			ft_free_split(strs, 0);
			return (index);
		}
		index++;
	}
	ft_free_split(strs, 0);
	return (-1);
}

int		check_and_freete(t_minirt *base, t_fonction *check_func, char *fd)
{
	char	*line;
	int		fd_open;

	fd_open = open(fd, O_RDONLY);
	init_struct_check(check_func);
	init_struct_cmp(base);
	while (get_next_line(fd_open, &line) > 0)
	{
		if (ft_strlen(line) > 0)
		{
			printf("\n#########check[line %s]#########\n", line);
			check_func->index = find_index(check_func->tabindex, line);
			if (check_func->index != -1)
				(check_func->tabfunction[check_func->index](line, base));
		}
		free(line);
	}
	if (ft_strlen(line) == 0)
		free(line);
	else if (ft_strlen(line) > 0)
	{
		printf("\n#########check[line %s]#########\n", line);
		check_func->index = find_index(check_func->tabindex, line);
		if (check_func->index != -1)
			(check_func->tabfunction[check_func->index](line, base));
		free(line);
	}
	close(fd_open);
	if (base->count_error != 0)
		return (-1);
	return (1);
}

void 	get_and_freete(t_minirt *base, t_fonction *tab_func, char *fd)
{
	char	*line;
	int		fd_open;

	fd_open = open(fd, O_RDONLY);
	init_struct_get(tab_func);
	init_forms_and_views(base);
	while (get_next_line(fd_open, &line) > 0)
	{
		if (ft_strlen(line) > 0)
		{
			printf("\n#########get[line %s]#########\n", line);
			tab_func->index = find_index(tab_func->tabindex, line);
			if (tab_func->index != -1)
				(tab_func->tabfunction_get[tab_func->index](line, base));
		}
		free(line);
	}
	if (ft_strlen(line) == 0)
		free(line);
	else
	{
		printf("\n#########get[line %s]#########\n", line);
		tab_func->index = find_index(tab_func->tabindex, line);
		if (tab_func->index != -1)
			(tab_func->tabfunction_get[tab_func->index](line, base));
		free(line);
	}
	close(fd_open);
}
