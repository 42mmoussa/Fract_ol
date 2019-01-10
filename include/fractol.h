/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussa <mmoussa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:23:26 by mmoussa           #+#    #+#             */
/*   Updated: 2019/01/10 15:23:28 by mmoussa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "../libft/libft.h"
# include <math.h>
# define HEIGHT 600
# define WIDTH 600

typedef struct	s_mlx
{
	char	*mlx;
	char	*win;
	void	*img;
	void	*img_ptr;
	float	z_x;
	float	z_y;
	float	x;
	float	y;
	float	a;
	float	aa;
	float	ca;
	float	b;
	float	bb;
	float	cb;
	float	c1;
	float	c2;
	int		color;
	int		lumin;
	int		bpp;
	int		sl;
	int		endian;
	int		psy;
	int		julia;
	int		mandelbrot;
	int		zoom;
	int		iter;
	char	*name;
	int		newton;
	int		pause;
}				t_mlx;

void			ft_draw_fractals(t_mlx *mlx);
void			ft_draw_newton(t_mlx *mlx);
int				julia_mouse(int x, int y, t_mlx *mlx);
void			ft_init(t_mlx *mlx, char *fracname);
int				loop_hook(t_mlx *mlx);
void			put_pixel_img(t_mlx *mlx, int x, int y, int color);
int				deal_mouse(int button, int x, int y, t_mlx *mlx);
int				deal_key(int key, t_mlx *mlx);
void			ft_draw(t_mlx *mlx);
void			ft_error(void);

#endif
