/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:43:02 by mmoussa           #+#    #+#             */
/*   Updated: 2018/11/11 13:20:53 by mmoussa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*ptr1;
	char	*ptr2;

	ptr1 = (char*)dest;
	ptr2 = (char*)src;
	if (n == 0)
		return (dest);
	while (n)
	{
		*ptr1++ = *ptr2++;
		n--;
	}
	return (dest);
}
