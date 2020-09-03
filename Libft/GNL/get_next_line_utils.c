/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tcurinie <tcurinie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:19:39 by tcurinie          #+#    #+#             */
/*   Updated: 2020/06/09 17:02:19 by Tcurinie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "../libft.h"

t_listGNL		*ft_lst_manage(t_listGNL *stock, int fd)
{
	t_listGNL	*temp;

	temp = stock;
	while (temp)
	{
		if (temp->fd == fd)
			return (temp);
		temp = temp->next;
	}
	return (0);
}

t_listGNL		*ft_lst_init(t_listGNL **alst, int fd)
{
	t_listGNL	*new;

	if (!(new = malloc(sizeof(t_listGNL))))
		return (NULL);
	if (!(new->content = ft_strdup_GNL("")))
		return (NULL);
	new->buff[0] = '\0';
	new->fd = fd;
	new->size = 0;
	new->next = NULL;
	new->before = NULL;
	if ((*alst))
	{
		new->next = (*alst);
		(*alst)->before = new;
		*alst = new;
	}
	else
	{
		*alst = new;
	}
	return (new);
}

char		*ft_strdup_GNL(char *s1)
{
	char	*dest;
	size_t	len;

	len = 0;
	while (s1[len])
		len++;
	if (!(dest = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	len = 0;
	while (s1[len])
	{
		dest[len] = s1[len];
		len++;
	}
	dest[len] = '\0';
	return (dest);
}

int			strlen_gnl(const char *line, char len)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			if (len == TRUE)
				return (i);
			return (ERROR);
		}
		i++;
	}
	return (i);
}

char		*ft_strjoinfree_GNL(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	if (!(dest = malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
		dest[i] = s1[i];
	j = -1;
	while (s2[++j])
		dest[i + j] = s2[j];
	dest[i + j] = '\0';
	free(s1);
	return (dest);
}
