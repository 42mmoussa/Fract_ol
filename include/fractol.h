#ifndef FRACTOL_H
# define FRACTOL_H

#include "mlx.h"
#include "../libft/libft.h"
#include <math.h>
#define height 1080
#define width 1920

typedef struct  s_mlx
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
	int		iteration;
	char	*name;
}				t_mlx;

int				julia_mouse(int x, int y, t_mlx *mlx);
void			ft_init(t_mlx *mlx, char *fracname);
int				loop_hook(t_mlx *mlx);
void			put_pixel_img(t_mlx *mlx, int x, int y, int color);
int				deal_mouse(int button, int x, int y, t_mlx *mlx);
int				deal_key(int key, t_mlx *mlx);
void   			ft_draw(t_mlx *mlx);
void			ft_error(void);

#endif