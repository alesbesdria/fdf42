#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"
#include <math.h>

void		ft_line(t_data *data, int xi, int yi, int xf, int yf, int color)
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

void		ft_bline(t_data *data,int xi,int yi,int xf,int yf, int color)
{
	double	dx;
	double	dy;
	double	sx;
	double	sy;
	double	err;
	double	e2;

	dx = abs(xf - xi);
	dy = abs(yf - yi);
	sx = (xi < xf) ? 1 : -1;
	sy = (yi < yf) ? 1 : -1;
	err = dx - dy;
	while (1)
	{
		mlx_pixel_put(data->ptr_mlx, data->ptr_win, xi, yi, color);
		if ((xi == xf) && (yi == yf))
			break;
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			xi += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			yi += sy;
		}
	}
}

void		map_read()
{
	int		tab[];
	int		len;
	int		x;
	int		y;
	int		z;

	ft_strsplit();
	ft_gnl();
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
	ft_bline(&data, 10, 10, 80, 80, 0x00FF0000);
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
