#include "fdf.h"

int			main(void)
{
	t_l			*mylist;
	t_file		*mymap;
	t_data		*data;
	t_mesh		*mesh;

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

	data->marg = 50;
	data->screen_height = 400;
	data->screen_width = 600;
	data->canvas_height = 400;
	data->canvas_width = 600;
	data->coef_elev = -10;
/*	data->scene_pos.x = 10;
	data->scene_pos.y = 10;
	data->scene_pos.z = 10;
	data->scene_rot.x = 0;
	data->scene_rot.y = pi;
	data->scene_rot.z = 0;*/

	data->ptr_mlx = mlx_init();
	data->ptr_win = mlx_new_window(data->ptr_mlx,
					data->screen_width, data->screen_height, "mlx 42");

	mlx_key_hook(data->ptr_win, modifhook, data);
	mlx_mouse_hook(data->ptr_win, mouseclick, data);
//	mlx_loop_hook (data->ptr_mlx, modifhook, data);
	mlx_hook(data->ptr_win, keypress, keypressmask, keymaintain, data);

	data->cam = set_cam(zero_vector3(), zero_vector3());
	data->cam->position = set_vector3(0, 0, 50);
	data->cam->target = set_vector3(0, 0, 0);

	mesh = malloc(sizeof(t_mesh));
	data->scene_pos = set_vector3(0, 0, 0);
	data->scene_rot = set_vector3(0.5, pi, 0.5);
	data->coef_init_elev = .3;
	data->coef_elev = data->coef_init_elev;

	data->put_in_canvas = true;

	data->back_buffer = 0;
	data->front_buffer = 1;
	data->img[data->back_buffer] = mlx_new_image(data->ptr_mlx,
		data->canvas_width, data->canvas_height);

	data->canvas[data->back_buffer] = (int *) mlx_get_data_addr(
		data->img[data->back_buffer], &data->bpp, &data->sizeline,
		&data->endian);

	data->img[data->front_buffer] = mlx_new_image(data->ptr_mlx,
		data->canvas_width, data->canvas_height);

	data->canvas[data->front_buffer] = (int *) mlx_get_data_addr(
		data->img[data->front_buffer], &data->bpp, &data->sizeline,
		&data->endian);

//	ft_bline(data, 0.0, 0, 100, 100, 0x00FF00FF);
	render_fdf(data);
	print_fdf(data);
//ft_bline_color(data, 0,0,400,400,0,10);
//	mlx_put_image_to_window(data->ptr_mlx, data->ptr_win,
//		data->img[data->back_buffer], 0, 0);

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
	mlx_loop(data->ptr_mlx);
	return (0);
}
