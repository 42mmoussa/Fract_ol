/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:36:44 by mmoussa           #+#    #+#             */
/*   Updated: 2018/11/13 13:44:40 by mmoussa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*ptr1;
	char	*ptr2;

	ptr1 = (char*)dest;
	ptr2 = (char*)src;
	if (dest > src)
	{
		while ((int)(--len) >= 0)
			*(ptr1 + len) = *(ptr2 + len);
	}
	else
	{
		while (len)
		{
			*ptr1++ = *ptr2++;
			len--;
		}
	}
	return (dest);
}
