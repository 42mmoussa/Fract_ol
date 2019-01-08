/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:02:14 by mmoussa           #+#    #+#             */
/*   Updated: 2018/11/10 12:18:29 by mmoussa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	char	*d;

	d = dest;
	if (len == 0)
		return (dest);
	while (len && *src)
	{
		*dest++ = *src++;
		len--;
	}
	while (len--)
		*dest++ = 0;
	return (d);
}
