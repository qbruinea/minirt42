/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbardet <jbardet@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:49:52 by jbardet           #+#    #+#             */
/*   Updated: 2020/02/20 11:52:16 by jbardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	**ft_free(char **strs, int k)
{
	while (k >= 0)
	{
		free(strs[k]);
		k--;
	}
	free(strs);
	return (NULL);
}

static int	ft_count(char const *s, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	if (!s[i])
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (words);
}

char		**ft_split(char const *s, char c)
{
	char	**strs;
	int		k;
	int		i;
	int		j;

	if (!s)
		return (ft_calloc(sizeof(char), 1));
	if (!(strs = malloc(sizeof(char **) * (ft_count(s, c) + 1))))
		return (NULL);
	i = 0;
	k = 0;
	j = 0;
	while (s[i] && k != ft_count(s, c))
	{
		i = j;
		while (s[i] == c && s[i])
			i++;
		j = i;
		while (s[j] != c && s[j])
			j++;
		if (!(strs[k++] = ft_substr(s, i, (j - i))))
			return (ft_free(strs, k));
	}
	strs[k] = NULL;
	return (strs);
}
