#include "fdf.h"

int		my_key_funct(int keycode, t_data *data)
{
	int toto;
	toto = data->marg;
	printf("%d\n", keycode);
	return (0);
}

int			main(void)
{
	t_l		*mylist;
	t_file	*mymap;
	t_data	*data;
	t_mesh	*mesh;
	
	mymap = NULL;
	mylist = NULL;
	mylist = initialisation();

	mymap = malloc(sizeof(t_file));
	data = malloc(sizeof(t_data));

	map_read(mymap, mylist);
	createtable(mymap->nbline, mymap->nbcol);
	createmap(mylist, mymap);

	data->tf = mymap;
	data->view_matrix = malloc(sizeof(t_matrix));
	data->projection_matrix = malloc(sizeof(t_matrix));
	data->world_matrix = malloc(sizeof(t_matrix));
	data->transform_matrix = malloc(sizeof(t_matrix));
//	mymap->nbcol = 10;
//	mymap->nbline = 8;
	data->marg = 50;
	data->screen_height = 400;
	data->screen_width = 600;
	data->canvas_height = 400;
	data->canvas_width = 600;
	data->ptr_mlx = mlx_init();
	data->ptr_win = mlx_new_window(data->ptr_mlx, data->screen_width, data->screen_height, "mlx 42");

	mlx_key_hook(data->ptr_win, modifhook, data);

	data->cam = set_cam(zero_vector3(), zero_vector3());
	data->cam->position = set_vector3(0, 0, 50);
	data->cam->target = set_vector3(0, 0, 0);

	mesh = malloc(sizeof(t_mesh));
	data->scene_pos = set_vector3(0, 0, 0);
	data->scene_rot = set_vector3(1, 0.5, 0.5);
	render_fdf(data);
	print_fdf(data);

/*	mlx_pixel_put(data->ptr_mlx, data->ptr_win, data->begin_map_x, data->begin_map_y, 0x00FFFF00);
	step(data, mymap);

	place_map(data);
	draw_grid(data, mymap);
*/
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
//	mlx_key_hook(data->ptr_win, my_key_funct, data);
//	int		my_key_funct(int keycode, void *param);
//	printf("key event %d\n", keycode);
//	mlx_hook(data->ptr_win, modifhook(data), 0);
	mlx_loop(data->ptr_mlx);
	return (0);
}
