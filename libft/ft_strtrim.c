/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussa <mmoussa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:07:40 by mmoussa           #+#    #+#             */
/*   Updated: 2018/11/13 18:02:10 by mmoussa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	j;
	char	*src;

	if (!s)
		return (0);
	if (!(src = ft_strnew(ft_strlen(s))))
		return (NULL);
	src = ft_strcpy(src, s);
	while (*src == ' ' || *src == '\n' || *src == '\t')
		src++;
	if (*src == 0)
		return (ft_strdup(src));
	j = ft_strlen(src) - 1;
	while ((src[j] == ' ' || src[j] == '\n' || src[j] == '\t') && j > 0)
		j--;
	j++;
	src = ft_strsub(src, 0, j);
	src[j] = 0;
	return (src);
}
