#include "../include/fractol.h"

void		ft_draw_phoenix(t_mlx *mlx)
{
	float	n;

	mlx->x = -1;
	while (++mlx->x < WIDTH)
	{
		mlx->y = -1;
		while (++mlx->y < HEIGHT)
		{
			mlx->ca = mlx->x / mlx->zoom + mlx->z_x;
			mlx->cb = mlx->y / mlx->zoom + mlx->z_y;
			mlx->a = 0;
			mlx->b = 0;
			n = -1;
			while (++n < mlx->iter && mlx->a * mlx->a + mlx->b * mlx->b < 4)
			{
				mlx->aa = mlx->a * mlx->a - mlx->b * mlx->b;
				mlx->bb = 2 * fabs(mlx->b * mlx->a);
				mlx->a = mlx->aa - mlx->ca;
				mlx->b = mlx->bb + mlx->cb;
			}
			put_pixel_img(mlx, mlx->x, mlx->y, n);
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
