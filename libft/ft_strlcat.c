/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:13:06 by mmoussa           #+#    #+#             */
/*   Updated: 2018/11/10 14:47:24 by mmoussa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	s1;

	i = 0;
	while (dest[i] && i < size)
		i++;
	s1 = i;
	if (size == 0)
		return (s1 + ft_strlen(src));
	while (src[i - s1] && i < size - 1)
	{
		dest[i] = src[i - s1];
		i++;
	}
	if (s1 < size)
		dest[i] = '\0';
	return (s1 + ft_strlen(src));
}
