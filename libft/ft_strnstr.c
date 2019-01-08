/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:42:58 by mmoussa           #+#    #+#             */
/*   Updated: 2018/11/10 16:15:10 by mmoussa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;
	int		stock;
	char	*str;

	str = (char*)haystack;
	stock = 0;
	i = 0;
	j = 0;
	if (*needle == 0)
		return (str);
	while (str[i] && i != (int)len)
	{
		j = 0;
		stock = i;
		while (needle[j] == str[i] && i != (int)len)
		{
			if (needle[j + 1] == '\0' && str[i] == needle[j])
				return (&str[stock]);
			i++;
			j++;
		}
		i = stock + 1;
	}
	return (0);
}
