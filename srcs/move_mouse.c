#include "../include/fractol.h"

int		loop_hook(t_mlx *mlx)
{
	static int		x = 0;
	static int		y = 0;
	static int		sx = 1;
	static int		sy = 1;

	if (mlx->psy == 1)
    {
        mlx_clear_window(mlx->mlx, mlx->win);
        mlx->color += 0x000003;
        if (x > width || x < 0)
            sx *= -1;
        else if (y > height || y < 0)
            sy *= -1;
        x = x + sx * 20;
        y = y + sy * 20;
        mlx->c1 = 1 - ((float)x / (float)(width / 2));
        mlx->c2 = 1 - ((float)y / (float)(height / 2));
        ft_draw(mlx);
    }
	return(0);
}

int     julia_mouse(int x, int y, t_mlx *mlx)
{
    if (mlx->julia == 1)
    {
        mlx_clear_window(mlx->mlx, mlx->win);
        mlx->c1 = 1 - ((float)x / (float)(width / 2));
        mlx->c2 = 1 - ((float)y / (float)(height / 2));
        ft_draw(mlx);
    }
    return(0);
}

int     deal_mouse(int button, int x, int y, t_mlx *mlx)
{
    ft_putnbr(button);
    mlx_clear_window(mlx->mlx, mlx->win);
    if (button == 2)
        mlx->color += 0x000003;
    if (button == 4)
    {
        mlx->z_x = ((float)x / mlx->zoom + mlx->z_x) - ((float)x / (mlx->zoom * 1.2));
        mlx->z_y = ((float)y / mlx->zoom + mlx->z_y) - ((float)y / (mlx->zoom * 1.2));
        mlx->zoom *= 1.2;
    }
    if (button == 7)
    {
        mlx->z_x = ((float)x / mlx->zoom + mlx->z_x) - ((float)x / (mlx->zoom / 1.2));
        mlx->z_y = ((float)y / mlx->zoom + mlx->z_y) - ((float)y / (mlx->zoom / 1.2));
        mlx->zoom /= 1.2;
    }
    ft_draw(mlx);
    return(0);
}
