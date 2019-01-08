#include "../include/fractol.h"

int			deal_key(int key, t_mlx *mlx)
{
	(void)mlx;
	if (key == 53)
		exit(1);
	else if (key == 35 && mlx->psy == 0)
		mlx->psy = 1;
	else if (key == 35 && mlx->psy == 1)
		mlx->psy = 0;
	ft_putnbr(key);
	if (key == 46)
	{
		mlx->z_x = -3.3;
		mlx->z_y = -1.65;
		mlx->zoom = 350;
		mlx->iteration = 1000;
		mlx->mandelbrot = 1;
		mlx->julia = 0;
	}
	if (key == 38)
	{
		mlx->z_x = -3;
		mlx->z_y = -1.6;
		mlx->zoom = 200;
		mlx->iteration = 1000;
		mlx->mandelbrot = 0;
		mlx->julia = 1;
	}
	if (key == 49)
		mlx->julia = mlx->julia == 0 ? 1 : 0;
	if (mlx->julia == 0 && mlx->mandelbrot == 0)
		mlx_string_put(mlx->mlx, mlx->win, 900, 525, 0xffffff, "|| PAUSE");
	return (0);
}
