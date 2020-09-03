/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:30:56 by Tcurinie          #+#    #+#             */
/*   Updated: 2020/08/13 23:19:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**ft_free_split(char **strs, int k)
{
	while (strs[k] != 0)
		k++;
	while (k >= 0)
	{
		free(strs[k]);
		k--;
	}
	free(strs);
	return (NULL);
}

static int    ft_count_cset(char const *s, char *set)
{
    int    words;
    int    i;

    words = 0;
    i = 0;
    if (!s[i])
        return (0);
    while (s[i])
    {
        while (is_valid_type(s[i], set) != -1)
            i++;
        if (is_valid_type(s[i], set) == -1 && s[i])
        {
            words++;
            while (s[i] && is_valid_type(s[i], set) == -1)
                i++;
        }
    }
    return (words);
}

char        **ft_split_cset(char const *s, char *set, int i)
{
    char    **strs;
    int        k;
    int        j;
    int     wc;

    if (!s)
        return (ft_calloc(sizeof(char), 1));
    wc = ft_count_cset(s, set);
    if (!(strs = malloc(sizeof(char **) * (wc + 1))))
        return (NULL);
    k = 0;
    j = 0;
    while (s[i] && k != wc)
    {
        i = j;
        while (is_valid_type(s[i], set) != -1 && s[i])
            i++;
        j = i;
        while (is_valid_type(s[j], set) == -1 && s[j])
            j++;
        if (!(strs[k++] = ft_substr(s, i, (j - i))))
            return ((char **)ft_free_split(strs, k));
    }
    strs[k] = NULL;
    return (strs);
}