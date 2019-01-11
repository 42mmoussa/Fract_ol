/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussa <mmoussa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:25:15 by mmoussa           #+#    #+#             */
/*   Updated: 2019/01/10 15:25:16 by mmoussa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		loop_hook(t_mlx *mlx)
{
	static int		x = 0;
	static int		y = 0;
	static int		sx = 1;
	static int		sy = 1;

	if (mlx->psy == 1)
	{
		mlx->color += 0x000003;
		if (x > WIDTH || x < 0)
			sx *= -1;
		else if (y > HEIGHT || y < 0)
			sy *= -1;
		x = x + sx * 20;
		y = y + sy * 20;
		mlx->c1 = 1 - ((float)x / (float)(WIDTH / 2));
		mlx->c2 = 1 - ((float)y / (float)(HEIGHT / 2));
		ft_draw_fractals(mlx);
	}
	return (0);
}

int		julia_mouse(int x, int y, t_mlx *mlx)
{
	if ((mlx->julia == 1 || mlx->newton == 1) && mlx->pause == 0)
	{
		mlx_clear_window(mlx->mlx, mlx->win);
		mlx->c1 = 1 - ((float)x / (float)(WIDTH / 2));
		mlx->c2 = 1 - ((float)y / (float)(HEIGHT / 2));
		ft_draw_fractals(mlx);
	}
	return (0);
}

int		deal_mouse(int button, int x, int y, t_mlx *mlx)
{
	if (button == 2)
	{
		mlx->color += 0x000003;
		ft_draw_fractals(mlx);
	}
	if (button == 4)
	{
		mlx->z_x = ((float)x / mlx->zoom + mlx->z_x) \
			- ((float)x / (mlx->zoom * 1.2));
		mlx->z_y = ((float)y / mlx->zoom + mlx->z_y) \
			- ((float)y / (mlx->zoom * 1.2));
		mlx->zoom *= 1.2;
		ft_draw_fractals(mlx);
	}
	if (button == 5)
	{
		mlx->z_x = ((float)x / mlx->zoom + mlx->z_x) \
			- ((float)x / (mlx->zoom / 1.2));
		mlx->z_y = ((float)y / mlx->zoom + mlx->z_y) \
			- ((float)y / (mlx->zoom / 1.2));
		mlx->zoom /= 1.2;
		ft_draw_fractals(mlx);
	}
	if (button == 1)
		mlx->pause = mlx->pause == 0 ? 1 : 0;
	return (0);
}
