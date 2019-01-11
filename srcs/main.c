/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussa <mmoussa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:24:55 by mmoussa           #+#    #+#             */
/*   Updated: 2019/01/10 15:24:55 by mmoussa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_window(char *name)
{
	t_mlx	*mlx;

	if (!(mlx = malloc(sizeof(t_mlx) + 1)))
		ft_error();
	if (!(mlx->mlx = mlx_init()))
		ft_error();
	ft_init(mlx, name);
	mlx_key_hook(mlx->win, &deal_key, mlx);
	mlx_hook(mlx->win, 6, 1L << 12, &julia_mouse, mlx);
	mlx_mouse_hook(mlx->win, &deal_mouse, mlx);
	mlx_loop_hook(mlx->mlx, &loop_hook, mlx);
	ft_draw_fractals(mlx);
	mlx_loop(mlx->mlx);
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr("usage: ./fractol julia | mandelbort | star | burningship\n");
		exit(1);
	}
	if (!ft_strequ(av[1], "mandelbrot") &&
			!ft_strequ(av[1], "julia") &&
				!ft_strequ(av[1], "star") &&
					!ft_strequ(av[1], "phoenix") &&
						!ft_strequ(av[1], "burningship"))
	{
		ft_putstr("usage: ./fractol julia | mandelbort | star | burningship\n");
		exit(1);
	}
	ft_window(ft_strdup(av[1]));
	return (0);
}
