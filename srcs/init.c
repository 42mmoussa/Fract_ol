#include "../include/fractol.h"

void    ft_init(t_mlx *mlx, char *name)
{
	mlx->name = name;
	mlx->mandelbrot = 0;
	mlx->c1 = 0;
	mlx->c2 = 0;
	mlx->color = 0x100230;
	mlx->psy = 0;
	mlx->mandelbrot = ft_strequ(mlx->name, "mandelbrot") == 1 ? 1 : 0;
	mlx->julia = ft_strequ(mlx->name, "julia") == 1 ? 1 : 0;
	mlx->zoom = 300;
	mlx->z_x = -3;
	mlx->z_y = -1.6;
	mlx->iteration = 250;
	mlx->img = mlx_new_image(mlx->mlx, width, height);
	mlx->img_ptr = mlx_get_data_addr(mlx->img, &(mlx->bpp), &(mlx->sl), &(mlx->endian));
	mlx->win = mlx_new_window(mlx->mlx, width, height, "mmoussa");
	mlx->z_x = -3.3;
}