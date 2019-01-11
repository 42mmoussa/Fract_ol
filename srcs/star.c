/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussa <mmoussa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:25:04 by mmoussa           #+#    #+#             */
/*   Updated: 2019/01/10 15:25:05 by mmoussa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void		ft_draw_star(t_mlx *mlx)
{
	float	n;

	mlx->x = -1;
	while (++mlx->x < WIDTH)
	{
		mlx->y = -1;
		while (++mlx->y < HEIGHT)
		{
			mlx->ca = mlx->x / mlx->zoom + mlx->z_x;
			mlx->cb = mlx->y / mlx->zoom + mlx->z_y;
			mlx->a = mlx->ca;
			mlx->b = mlx->cb;
			n = -1;
			while (++n < mlx->iter && mlx->a + mlx->b < 16)
			{
				mlx->aa = (pow(mlx->a, 2) - pow(mlx->b, 2) * 4) * \
					mlx->a * pow(-1, n);
				mlx->bb = (mlx->a * mlx->a * 4 - pow(mlx->b, 2)) * mlx->b;
				mlx->a = mlx->aa + 0.0;
				mlx->b = mlx->bb + 0.75;
			}
			put_pixel_img(mlx, mlx->x, mlx->y, n);
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
