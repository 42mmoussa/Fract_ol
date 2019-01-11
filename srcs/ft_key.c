/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussa <mmoussa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:24:44 by mmoussa           #+#    #+#             */
/*   Updated: 2019/01/10 15:24:45 by mmoussa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	ft_switch(int key, t_mlx *mlx)
{
	mlx->z_x = -2;
	mlx->z_y = -2;
	mlx->zoom = 150;
	mlx->mandelbrot = 0;
	mlx->julia = 0;
	mlx->star = 0;
	if (key == 18)
		mlx->mandelbrot = 1;
	else if (key == 19)
		mlx->julia = 1;
	else if (key == 20)
		mlx->star = 1;
	else if (key == 21)
		mlx->phoenix = 1;
	else if (key == 23)
	{
		mlx->zoom = 2500;
		mlx->z_x = 1.57;
		mlx->z_y = -0.15;
		mlx->ship = 1;
	}
}

int			deal_key(int key, t_mlx *mlx)
{
	ft_putnbr(key);
	if (key == 53)
		exit(1);
	else if (key == 24)
		mlx->x += 0.1;
	else if (key == 35 && (mlx->julia == 1 || mlx->star == 1))
		mlx->psy = mlx->psy == 0 ? 1 : 0;
	else if ((key >= 18 && key <= 21) || key == 23)
		ft_switch(key, mlx);
	if (key == 35 || key == 23 || (key >= 18 && key <= 21))
		ft_draw_fractals(mlx);
	return (0);
}
