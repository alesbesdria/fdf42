#include "fdf.h"

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
/*
void		line_trace(t_l *mylist, t_file *mymap)
{
	t_z		*curr;
	curr = mylist->first;
	createmap(mylist, mymap);
	while (curr != NULL)
	{
		ft_bline(mylist, curr, curr, curr->next, curr->next, 0x00FFFFFF);
	}
}
*/

void		place_map(t_data *data, t_file *mymap)
{
	printf("mymap->nbcol : %d\n", mymap->nbcol);
	printf("mymap->nbline : %d\n", mymap->nbline);
	printf("screen_width : %d\n", data->screen_width);
	printf("screen_height : %d\n", data->screen_height);
	printf("marg : %d\n", data->marg);


	data->width_map = (data->screen_width - data->marg * 2);
	data->height_map = (data->screen_height - data->marg * 2);
	printf("width_map : %d\n", data->width_map);
	printf("height_map : %d\n", data->height_map);

	data->middle_screen_x = data->screen_width / 2;

	printf("middle_screen_x : %d\n", data->middle_screen_x);

	data->middle_screen_y = data->screen_height / 2;

	printf("middle_screen_y : %d\n", data->middle_screen_y);

	data->begin_map_x = data->middle_screen_x - data->width_map / 2;

	printf("begin_map_x : %d\n", data->begin_map_x);

	data->begin_map_y = data->middle_screen_y - data->height_map / 2;

	printf("begin_map_y : %d\n", data->begin_map_y);
}

void		step(t_data *data, t_file *mymap)
{
	data->step_x = data->width_map / (mymap->nbcol - 1);
	data->step_y = data->height_map / (mymap->nbline - 1);
	printf("step_x : %d\n", data->step_x);
	printf("step_y : %d\n", data->step_y);
}

int			main(void)
{
	t_l		*mylist;
	t_file	*mymap;
	t_data	*data;
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
//	int		pixelnext_y;

	i = 0;
	j = 0;
	mymap = NULL;
	mymap = malloc(sizeof(t_file));
	data = malloc(sizeof(t_data));
	mymap->nbcol = 10;
	mymap->nbline = 8;
	data->marg = 20;
	data->screen_height = 400;
	data->screen_width = 600;
	place_map(data, mymap);
	mylist = initialisation();
	data->ptr_mlx = mlx_init();
	data->ptr_win = mlx_new_window(data->ptr_mlx, data->screen_width, data->screen_height, "mlx 42");
	mlx_pixel_put(data->ptr_mlx, data->ptr_win, data->begin_map_x, data->begin_map_y, 0x00FFFF00);
	step(data, mymap);
	pixelnext_x = data->begin_map_x + data->step_x;
	pixelnext_y = data->begin_map_y + data->step_y;
	printf("pixelnext_x : %d\n", pixelnext_x);
//	pixelnext_y = data->begin_map_y + data->step_y;
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
	//	mlx_pixel_put(data.ptr_mlx, data.ptr_win, 200, 200, 0x00FFFFFF);
//	ft_line(&data, 250, 250, 350, 350, 0x00FF00FF);
//	ft_bline(&data, 10, 10, 80, 80, 0x00FF0000);
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
	mlx_loop(data->ptr_mlx);
	return (0);
}
