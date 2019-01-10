/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussa <mmoussa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:24:50 by mmoussa           #+#    #+#             */
/*   Updated: 2019/01/10 15:24:50 by mmoussa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_init(t_mlx *mlx, char *name)
{
	mlx->name = name;
	mlx->mandelbrot = 0;
	mlx->c1 = 0;
	mlx->c2 = 0;
	mlx->color = 0x100230;
	mlx->psy = 0;
	mlx->mandelbrot = ft_strequ(mlx->name, "mandelbrot") == 1 ? 1 : 0;
	mlx->julia = ft_strequ(mlx->name, "julia") == 1 ? 1 : 0;
	mlx->newton = ft_strequ(mlx->name, "newton") == 1 ? 1 : 0;
	mlx->zoom = 150;
	mlx->z_x = -2;
	mlx->z_y = -2;
	mlx->iter = 200;
	mlx->pause = 0;
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->img_ptr = mlx_get_data_addr(mlx->img, &(mlx->bpp), &(mlx->sl),\
		&(mlx->endian));
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "mmoussa");
}
