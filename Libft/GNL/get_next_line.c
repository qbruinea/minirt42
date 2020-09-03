/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tcurinie <tcurinie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:19:17 by tcurinie          #+#    #+#             */
/*   Updated: 2020/06/09 17:00:35 by Tcurinie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "../libft.h"

int		ft_read(t_listGNL *current, t_listGNL **stock)
{
	int ret;

	ret = read(current->fd, current->buff, BUFFER_SIZE);
	current->buff[ret] = '\0';
	current->size = BUFFER_SIZE - ret;
	if (!(current->content = ft_strjoinfree_GNL(current->content, current->buff)))
		return (ft_lstfreeone(current, stock, FALSE));
	if (current->size != 0 && current->buff[ret - 1] == '\n')
	{
		if (!(current->content = ft_strjoinfree_GNL(current->content, "\n")))
			return (ft_lstfreeone(current, stock, FALSE));
	}
	return (1);
}

int		ft_write(char **line, t_listGNL *current)
{
	int		i;
	char	*temp;

	if (!(temp = malloc(1 * (strlen_gnl(current->content, TRUE) + 1))))
		return (0);
	i = 0;
	while (((char*)current->content)[i] && ((char*)current->content)[i] != '\n')
	{
		temp[i] = ((char*)current->content)[i];
		i++;
	}
	temp[i] = '\0';
	if (!(*line = ft_strdup_GNL(temp)))
		return (0);
	free(temp);
	temp = NULL;
	if (((char*)current->content)[i] == '\n')
		i++;
	if (!(temp = ft_strdup_GNL(&current->content[i])))
		return (0);
	free(current->content);
	if (!(current->content = ft_strdup_GNL(temp)))
		return (0);
	free(temp);
	return (1);
}

int		ft_lstfreeone(t_listGNL *current, t_listGNL **stock, int re)
{
	if (current->before != NULL)
		current->before->next = current->next;
	if (current->next != NULL)
		current->next->before = current->before;
	if (current->before == NULL)
	{
		if (current->next == NULL)
			(*stock) = NULL;
		(*stock) = current->next;
	}
	free(current->content);
	current->next = NULL;
	current->before = NULL;
	free(current);
	current = NULL;
	return (re);
}

int		get_next_line(int fd, char **line)
{
	static t_listGNL	*stock;
	t_listGNL			*current;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, *line, 0) < 0)
		return (ERROR);
	if ((current = ft_lst_manage(stock, fd)) == 0)
		current = ft_lst_init(&stock, fd);
	while (strlen_gnl(current->content, FALSE) != -1 && current->size == 0)
	{
		if (!(ft_read(current, &stock) == 1))
			return (ERROR);
	}
	if (!(ft_write(line, current)))
		return (ft_lstfreeone(current, &stock, ERROR));
	if (current->size != 0 && strlen_gnl(current->content, FALSE) == 0)
		return (ft_lstfreeone(current, &stock, FALSE));
	return (1);
}
