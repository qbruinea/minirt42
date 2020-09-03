/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbardet <jbardet@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:54:37 by jbardet           #+#    #+#             */
/*   Updated: 2020/02/20 11:53:19 by jbardet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*src;
	char	*dest;

	src = (char *)s;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(src) || len == 0)
		return (ft_strdup("\0"));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (!(dest = ft_calloc((len + 1), sizeof(char))))
		return (NULL);
	i = 0;
	while (src[start] && i < len)
		dest[i++] = src[start++];
	return (dest);
}
