#include "mm_graph.h"

t_cam				new_cam()
{
	t_cam			result;

	result.position = zero_vector3();
	result.target = zero_vector3();
	return (result);
}

t_cam				*set_cam(t_vector3 pos, t_vector3 target)
{
	t_cam			*camera;

	camera = malloc(sizeof(t_cam));
	camera->position.x = pos.x;
	camera->position.y = pos.y;
	camera->position.z = pos.z;
	camera->target.x = target.x;
	camera->target.y = target.y;
	camera->target.z = target.z;
	return (camera);
}

void	clear_screen(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->canvas_height)
	{
		j = 0;
		while (j < data->canvas_width)
		{
//			mlx_pixel_put2(data->ptr_mlx, data->ptr_win, j, i, 0x00000000);
			mlx_pixel_put2(data, j, i, 0x00000000);
			j++;
		}
		i++;
	}
}

t_vector2			project_device(t_data *data, t_vector3 coord, t_matrix tMat)
{
	t_vector3		point;
	double			x;
	double			y;

	point = transform_coord_vector3(coord, tMat);
	x = round((point.x * data->canvas_width) + (data->canvas_width / 2.0));
	y = round((point.y * data->canvas_height) + (data->canvas_height / 2.0));
	return (new_vector2(x, y));
}

void				draw_point_device(t_data *data, t_vector2 point)
{
	int			color;
	t_color4	color4;

	color4 = new_color4(0, 0xFF,0xFF, 0xFF);
	color = (((color4.a * 0xFF + color4.r) * 0xFF + color4.g) * 0xFF) 
		+ color4.b;
	if(point.x >= 0 && point.y >= 0 && point.x < data->canvas_width && point.y 
		< data->canvas_height) {
		mlx_pixel_put2(data, point.x, point.y, color);
	}
}

int			clip_v2(t_data *data, t_vector2 *pj1, t_vector2 *pj2)
{
	short		pj1_in_canvas;
	short		pj2_in_canvas;
	int			result[4];
	t_vector2	intersect1;
	t_vector2	intersect2;
	short		nb_intersect;
	t_vector2	array_inters[8];
	int			i;

	if (((pj1->x >= 0) && (pj1->x <= data->canvas_width)) &&
	   ((pj1->y >= 0) && (pj1->y <= data->canvas_height)))
		pj1_in_canvas = 1;
		else
		pj1_in_canvas = 0;
	if (((pj2->x >= 0) && (pj2->x <= data->canvas_width)) &&
	   ((pj2->y >= 0) && (pj2->y <= data->canvas_height)))
		pj2_in_canvas = 1;
		else
		pj2_in_canvas = 0;
	if (pj1_in_canvas && pj2_in_canvas)
		return (1);

	result[0] = lines_intersect(pj1->x, pj1->y, pj2->x, pj2->y, 0, 0,
		data->canvas_width, 0,  &array_inters[0].x, &array_inters[0].y);
	result[1] = lines_intersect(pj1->x, pj1->y, pj2->x, pj2->y,
		data->canvas_width, 0, data->canvas_width, data->canvas_height,
		&array_inters[1].x, &array_inters[1].y);
	result[2] = lines_intersect(pj1->x, pj1->y, pj2->x, pj2->y,
		data->canvas_width, data->canvas_height, 0, data->canvas_height,
		&array_inters[2].x, &array_inters[2].y);
	result[3] = lines_intersect(pj1->x, pj1->y, pj2->x, pj2->y,
		0, data->canvas_height, 0, 0, &array_inters[3].x, &array_inters[3].y);
	nb_intersect = 0;
	i = 0;
	while (i <= 3)
	{
		if (result[i] == do_intersect)
		{
			if (nb_intersect == 0)
				intersect1 = array_inters[i];
				else
				intersect2 = array_inters[i];
			nb_intersect++;
		}
		i++;
	}
	if (nb_intersect == 2)
	{
		*pj1 = intersect1;
		*pj2 = intersect2;
		return (1);
	}
	else
	if (nb_intersect == 1)
	{
		if (pj1_in_canvas)
		{
			*pj2 = intersect1;
		}
		else
		{
			*pj1 = intersect1;
		}
		return (1);
	}
	return (0);
}

void			print_fdf(t_data *data)
{
	int			i;
	int			j;
	int			result;
	t_vector3	tv1;
	t_vector3	tv2;
	t_vector2	pj1;
	t_vector2	pj2;

	for (i = 0; i < data->tf->nbline; i++)
	{
		for (j = 0; j < data->tf->nbcol; j++)
		{
			if (j < data->tf->nbcol - 1)
			{
				tv1 = data->tf->map[i][j];
				tv2 = data->tf->map[i][j+1];
				tv1.z *= data->coef_elev;
				tv2.z *= data->coef_elev;
				pj1 = project_device(data, tv1, *data->transform_matrix);
				pj2 = project_device(data, tv2, *data->transform_matrix);
				tv1.z /= data->coef_elev;
				tv2.z /= data->coef_elev;
				if (clip_v2(data, &pj1, &pj2))
				{
//					printf("i:%d j:%d %le %le %le %le\n", i, j, pj1.x, pj1.y, pj2.x, pj2.y);
					ft_bline_color(data, pj1.x, pj1.y, pj2.x,
						pj2.y, tv1.z, tv2.z);
//					ft_bline(data, pj1.x, pj1.y, pj2.x,
//						pj2.y, 0x00FFFFFF);
//						printf("%le %le");
				}
			}
			if (i < data->tf->nbline - 1)
			{
				tv1 = data->tf->map[i][j];
				tv2 = data->tf->map[i+1][j];
				tv1.z *= data->coef_elev;
				tv2.z *= data->coef_elev;
				pj1 = project_device(data, tv1, *data->transform_matrix);
				pj2 = project_device(data, tv2, *data->transform_matrix);
				tv1.z /= data->coef_elev;
				tv2.z /= data->coef_elev;
				if (clip_v2(data, &pj1, &pj2))
				{
//					printf("i:%d j:%d %le %le %le %le\n", i, j, pj1.x, pj1.y, pj2.x, pj2.y);
					ft_bline_color(data, pj1.x, pj1.y, pj2.x,
						pj2.y, tv1.z, tv2.z);
//					ft_bline(data, pj1.x, pj1.y, pj2.x,
//						pj2.y, 0x00FFFFFF);
				}
			}
		}
	}
	result = mlx_put_image_to_window (data->ptr_mlx, data->ptr_win,
		data->img[data->back_buffer], 1, 0);
}

void			render_fdf(t_data *data)
{
	*data->view_matrix = look_at_lh_matrix(data->cam->position,
		data->cam->target, up_vector3());
	*data->projection_matrix = perspective_fov_lh_matrix(0.78,
		data->canvas_width / data->canvas_height, 0.01, 1);
	*data->world_matrix = multiply_matrix(rot_yaw_pitch_roll_matrix(
		data->scene_rot.y, data->scene_rot.x, data->scene_rot.z),
		translation_matrix(data->scene_pos.x, data->scene_pos.y, 
		data->scene_pos.z));
	*data->transform_matrix = multiply_matrix(*data->world_matrix,
		multiply_matrix(*data->view_matrix, *data->projection_matrix));
}
