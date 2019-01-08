/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 09:56:54 by mmoussa           #+#    #+#             */
/*   Updated: 2019/01/03 11:38:29 by mmoussa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_end_line(char *stock)
{
	int		i;

	i = 0;
	while (stock[i] != '\n' && stock[i])
		i++;
	return (i);
}

char	*ft_end_file(char *stock, int j)
{
	if (ft_strchr(stock, '\n'))
	{
		ft_strcpy(stock, stock + j + 1);
		return (stock);
	}
	if (j > 0)
	{
		ft_strcpy(stock, stock + j);
		return (stock);
	}
	return (NULL);
}

int		get_next_line(const int fd, char **line)
{
	static char	*stock;
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	int			i;

	if (fd < 0 || !line || BUFF_SIZE < 0 || read(fd, buff, 0) < 0
		|| (!stock && !(stock = ft_strnew(0))))
		return (-1);
	while (!(ft_strchr(stock, '\n')) && (i = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[i] = 0;
		tmp = stock;
		stock = ft_strjoin(tmp, buff);
		free(tmp);
	}
	*line = ft_strsub(stock, 0, ft_end_line(stock));
	if (ft_end_file(stock, ft_end_line(stock)))
		return (1);
	return (0);
}
