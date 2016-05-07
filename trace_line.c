#include "trace_line.h"

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

void		place_map(t_data *data)
{
	data->width_map = (data->screen_width - data->marg * 2);
	data->height_map = (data->screen_height - data->marg * 2);
	data->middle_screen_x = data->screen_width / 2;
	data->middle_screen_y = data->screen_height / 2;
	data->begin_map_x = data->middle_screen_x - data->width_map / 2;
	data->begin_map_y = data->middle_screen_y - data->height_map / 2;
}

void		step(t_data *data, t_file *mymap)
{
	data->step_x = data->width_map / (mymap->nbcol - 1);
	data->step_y = data->height_map / (mymap->nbline - 1);
}

void		draw_grid(t_data *data, t_file *mymap)
{
	int		pixelnext_x;
	int		pixelnext_y;
	int		pixelnext_xi;
	int		pixelnext_yi;
	int		i;
	int		j;
	int		newbegin_x;
	int		newbegin_y;
	int		newbegin_xi;
	int		newbegin_yi;

	i = 0;
	j = 0;
	data->marg = 50;
	data->screen_height = 400;
	data->screen_width = 600;
	place_map(data);
	step(data, mymap);
	pixelnext_x = data->begin_map_x + data->step_x;
	pixelnext_y = data->begin_map_y + data->step_y;
	newbegin_x = data->begin_map_x;
	newbegin_y = data->begin_map_y;
	while (j < mymap->nbline - 1)
	{
		i = 0;
		if (j == 0)
		{
			newbegin_xi = data->begin_map_x;
			newbegin_yi = data->begin_map_y;
			pixelnext_xi = data->begin_map_x + data->step_x;
			pixelnext_yi = data->begin_map_y + data->step_y;
		}
		newbegin_xi = newbegin_x;
		newbegin_yi = newbegin_y;
		pixelnext_xi = pixelnext_x;
		pixelnext_yi = pixelnext_y;
		while (i < mymap->nbcol - 1)
		{
			ft_bline(data, newbegin_xi, newbegin_yi, pixelnext_xi, newbegin_yi, 0x00FF00FF);
			ft_bline(data, newbegin_xi, newbegin_yi, newbegin_xi, pixelnext_yi, 0x00FF00FF);
			newbegin_xi = newbegin_xi + data->step_x;
			pixelnext_xi = pixelnext_xi + data->step_x;
			if (i == mymap->nbcol - 2)
				ft_bline(data, newbegin_xi, newbegin_yi, newbegin_xi, pixelnext_yi, 0x00FF00FF);
			if (j == mymap->nbline - 2)
				ft_bline(data, newbegin_x, newbegin_y, pixelnext_x, newbegin_y, 0x00FF00FF);
			i++;
		}
		newbegin_y = newbegin_y + data->step_y;
		pixelnext_y = pixelnext_y + data->step_y;
		if (j == mymap->nbline - 2)
		{
			i = 0;
			while (i < mymap->nbcol - 1)
			{
				ft_bline(data, newbegin_x, newbegin_y, pixelnext_x, newbegin_y, 0x00FF00FF);
				newbegin_x = newbegin_x + data->step_x;
				pixelnext_x = pixelnext_x + data->step_x;
				i++;
			}
		}
		j++;
	}
}
