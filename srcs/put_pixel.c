/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussa <mmoussa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:25:20 by mmoussa           #+#    #+#             */
/*   Updated: 2019/01/10 15:25:23 by mmoussa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	put_pixel_img(t_mlx *mlx, int x, int y, int n)
{
	mlx->lumin = 0;
	if (n == mlx->iter)
		mlx->lumin = 0xFFFF55;
	else
		mlx->lumin = mlx->color * n;
	if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT)
	{
		mlx->lumin = mlx_get_color_value(mlx->mlx, mlx->lumin);
		ft_memcpy(mlx->img_ptr + 4 * WIDTH * y + x * 4, &mlx->lumin, \
			sizeof(int));
	}
}
