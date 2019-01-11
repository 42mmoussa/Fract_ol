/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_frac.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussa <mmoussa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:23:40 by mmoussa           #+#    #+#             */
/*   Updated: 2019/01/10 15:24:15 by mmoussa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_draw_fractals(t_mlx *mlx)
{
	if (mlx->julia == 1 || mlx->mandelbrot == 1)
		ft_draw(mlx);
	else if (mlx->star == 1)
		ft_draw_star(mlx);
	else if (mlx->phoenix == 1)
		ft_draw_phoenix(mlx);
	else if (mlx->ship == 1)
		ft_draw_burningship(mlx);
}
