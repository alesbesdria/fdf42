#include "fdf.h"
#include <stdio.h>
#include "mlx.h"

void		ft_line(t_data *data, int xi, int xf, int yi, int yf, int color)
{
	int				x;
	int				y;
	double			a;
	double			b;

	a = (double)(yf - yi) / (xf - xi);
	b = yi - a * xi;
	printf("toto");
	x = xi;
	while (x <= xf)
	{
		y = (int)(a * x + b);
		mlx_pixel_put(data->ptr_mlx, data->ptr_win, x, y, color);
		x++;
	}
}

int			main(void)
{
	t_data	data;
	int		x;
	int		y;

	data.ptr_mlx = mlx_init();
	data.ptr_win = mlx_new_window(data.ptr_mlx, 400, 400, "mlx 42");
//	mlx_pixel_put(data.ptr_mlx, data.ptr_win, 200, 200, 0x00FFFFFF);
	ft_line(&data, 250, 250, 350, 350, 0x00FF00FF);
/*
	y = 50;
	while (y < 150)
	{
		x = 50;
		while (x < 150)
		{
			mlx_pixel_put(data.ptr_mlx, data.ptr_win, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
*/
//	mlx_hook(win, my_key_funct, 0);
//	int		my_key_funct(int keycode, void *param);
//	printf("key event %d\n", keycode);
	mlx_loop(data.ptr_mlx);
	return (0);
}
