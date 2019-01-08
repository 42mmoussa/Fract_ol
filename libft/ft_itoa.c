/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussa <mmoussa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:48:27 by mmoussa           #+#    #+#             */
/*   Updated: 2018/11/13 14:33:27 by mmoussa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	str[10];
	char	*dest;
	int		i;
	int		nbr;

	i = 0;
	nbr = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	if (nbr < 0)
		nbr = -n;
	while (nbr > 0)
	{
		str[i++] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	if (n < 0)
		str[i++] = '-';
	if (!(dest = ft_strnew(i)))
		return (NULL);
	while (--i >= 0)
		dest[nbr++] = str[i];
	return (dest);
}
