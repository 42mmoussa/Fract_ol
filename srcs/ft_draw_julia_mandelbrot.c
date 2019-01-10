/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_julia_mandelbrot.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussa <mmoussa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:24:34 by mmoussa           #+#    #+#             */
/*   Updated: 2019/01/10 15:24:36 by mmoussa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdio.h>

static void	ft_draw_julia(t_mlx *mlx)
{
	mlx->ca = mlx->x / mlx->zoom + mlx->z_x;
	mlx->cb = mlx->y / mlx->zoom + mlx->z_y;
	mlx->a = mlx->ca;
	mlx->b = mlx->cb;
}

static void	ft_draw_mandelbrot(t_mlx *mlx)
{
	mlx->ca = mlx->x / mlx->zoom + mlx->z_x;
	mlx->cb = mlx->y / mlx->zoom + mlx->z_y;
	mlx->a = 0;
	mlx->b = 0;
}

static void	ft_draw_frac(t_mlx *mlx)
{
	if (mlx->julia == 1)
		ft_draw_julia(mlx);
	if (mlx->mandelbrot == 1)
		ft_draw_mandelbrot(mlx);
}

void		ft_draw(t_mlx *mlx)
{
	float	n;

	mlx->x = -1;
	while (++mlx->x < WIDTH)
	{
		mlx->y = -1;
		while (++mlx->y < HEIGHT)
		{
			ft_draw_frac(mlx);
			n = -1;
			while (++n < mlx->iter)
			{
				mlx->aa = mlx->a * mlx->a - mlx->b * mlx->b;
				mlx->bb = 2 * mlx->a * mlx->b;
				if (fabs(mlx->aa + 2 * (mlx->b * mlx->b)) > 4)
					break ;
				mlx->c1 = mlx->mandelbrot == 1 ? mlx->ca : mlx->c1;
				mlx->c2 = mlx->mandelbrot == 1 ? mlx->cb : mlx->c2;
				mlx->a = mlx->aa + mlx->c1;
				mlx->b = mlx->bb + mlx->c2;
			}
			put_pixel_img(mlx, mlx->x, mlx->y, n);
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
