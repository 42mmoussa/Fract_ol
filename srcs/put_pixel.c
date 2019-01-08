#include "../include/fractol.h"

void	put_pixel_img(t_mlx *mlx, int x, int y, int n)
{
	mlx->lumin = 0;
	if (n == mlx->iteration)
		mlx->lumin = 0;
	else
		mlx->lumin = mlx->color * n;
	if (x >= 0 && y >= 0 && x < width && y < height)
	{
		mlx->lumin = mlx_get_color_value(mlx->mlx, mlx->lumin);
		ft_memcpy(mlx->img_ptr + 4 * width * y + x * 4, &mlx->lumin, sizeof(int));
	}
}
