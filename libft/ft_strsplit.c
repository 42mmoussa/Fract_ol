/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussa <mmoussa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 21:46:15 by mmoussa           #+#    #+#             */
/*   Updated: 2018/11/12 15:09:44 by mmoussa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrwords(char const *s, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static int	ft_wordlen(const char *s, char c, int i)
{
	int		j;

	j = 0;
	while (s[i + j] != c && s[i + j])
		j++;
	return (j);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	size_t	k;
	char	**str;

	k = 0;
	i = 0;
	if (!s || !(str = (char **)malloc(sizeof(*str) * (ft_nbrwords(s, c) + 1))))
		return (NULL);
	while (s[k] && i < ft_nbrwords(s, c))
	{
		j = 0;
		while (s[k] == c)
			k++;
		if (!(str[i] = ft_strnew(ft_wordlen(s, c, k) + 1)))
			str[i] = NULL;
		while (s[k] != c && s[k])
			str[i][j++] = s[k++];
		str[i][j] = '\0';
		i++;
	}
	str[i] = 0;
	return (str);
}
