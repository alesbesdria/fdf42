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

//t_vector2			project_device(t_device dev, t_vector3 coord, t_matrix tMat)
t_vector2			project_device(t_data *data, t_vector3 coord, t_matrix tMat)
{
	t_vector3		point;
	double			x;
	double			y;

	point = transform_coord_vector3(coord, tMat);
	//	x = round((point.x * device.workingWidth) + (device.workingWidth / 2.0)) >> 0;
	x = round((point.x * data->canvas_width) + (data->canvas_width / 2.0));
	y = round((point.y * data->canvas_height) + (data->canvas_height / 2.0));
//printf("x: %lf, y: %lf///\n",x,y);
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
/*
t_mesh				*new_cube(char *name)
{
	t_mesh			*my_cube;

	my_cube = new_mesh(name, 8, 12);
	my_cube->vertices[0] = set_vector3(-1,  1,  1);
	my_cube->vertices[1] = set_vector3( 1,  1,  1);
	my_cube->vertices[2] = set_vector3(-1, -1,  1);
	my_cube->vertices[3] = set_vector3( 1, -1,  1);
	my_cube->vertices[4] = set_vector3(-1,  1, -1);
	my_cube->vertices[5] = set_vector3( 1,  1, -1);
	my_cube->vertices[6] = set_vector3( 1, -1, -1);
	my_cube->vertices[7] = set_vector3(-1, -1, -1);
	my_cube->length = 8;
	put_face(&my_cube->faces[0],  0, 1, 2);
	put_face(&my_cube->faces[1],  1, 2, 3);
	put_face(&my_cube->faces[2],  1, 3, 6);
	put_face(&my_cube->faces[3],  1, 5, 6);
	put_face(&my_cube->faces[4],  0, 1, 4);
	put_face(&my_cube->faces[5],  1, 4, 5);
	put_face(&my_cube->faces[6],  2, 3, 7);
	put_face(&my_cube->faces[7],  3, 6, 7);
	put_face(&my_cube->faces[8],  0, 2, 7);
	put_face(&my_cube->faces[9],  0, 4, 7);
	put_face(&my_cube->faces[10], 4, 5, 6);
	put_face(&my_cube->faces[11], 4, 6, 7);
	return my_cube;
}

void				printcube(t_mesh *my_cube)
{
	printf("Nom du cube : %s\n",my_cube->name);
	for(int i = 0 ; i < 8; i++)
		printf("Vertex n° %d : x=%f, y=%f, z=%f\n",i,my_cube->vertices[i].x,
				my_cube->vertices[i].y,my_cube->vertices[i].z);
	for(int i = 0 ; i < 12; i++)
		printf("Face n° %d : A=%f, B=%f, C=%f\n",i,my_cube->faces[i].a,
				my_cube->faces[i].b,my_cube->faces[i].c);
}

void 			render(t_data *data, t_meshes *meshes)
{
	t_matrix	viewMatrix;
	t_matrix	projectionMatrix;
	t_matrix	worldMatrix;
	t_matrix	transformMatrix;
	long long	index;
	long long	indexvertices;
	t_mesh		*cMesh;
	t_vector2	projectedPoint;
	t_vector2	tv[12];

	viewMatrix = look_at_lh_matrix(data->cam->position, data->cam->target, 
		up_vector3());
	projectionMatrix = perspective_fov_lh_matrix(0.78, 
		data->canvas_width / data->canvas_height, 0.01, 1);
	for (index = 0; index < meshes->length; index++)
	{
		cMesh = meshes->m[index];
		worldMatrix = multiply_matrix(rot_yaw_pitch_roll_matrix(
			cMesh->rotation.y, cMesh->rotation.x, cMesh->rotation.z),
			translation_matrix(cMesh->position.x, cMesh->position.y, 
			cMesh->position.z));
			transformMatrix = multiply_matrix(worldMatrix,multiply_matrix(
				viewMatrix,projectionMatrix));
		for (indexvertices = 0; indexvertices < cMesh->length; indexvertices++)
		{
			projectedPoint = project_device(data, 
				cMesh->vertices[indexvertices], transformMatrix);
//			draw_point_device (data, projectedPoint);
			tv[indexvertices] = projectedPoint;
		}

		fdf_bline(data, tv[0].x, tv[0]. y,tv[1].x, tv[1].y, 0x00FFFFFF);
		fdf_bline(data, tv[1].x, tv[1]. y,tv[3].x, tv[3].y, 0x00FFFFFF);
		fdf_bline(data, tv[3].x, tv[3]. y,tv[2].x, tv[2].y, 0x00FFFFFF);
		fdf_bline(data, tv[2].x, tv[2]. y,tv[0].x, tv[0].y, 0x00FFFFFF);
		fdf_bline(data, tv[4].x, tv[4]. y,tv[5].x, tv[5].y, 0x00FFFFFF);
		fdf_bline(data, tv[5].x, tv[5]. y,tv[6].x, tv[6].y, 0x00FFFFFF);
		fdf_bline(data, tv[6].x, tv[6]. y,tv[7].x, tv[7].y, 0x00FFFFFF);
		fdf_bline(data, tv[7].x, tv[7]. y,tv[4].x, tv[4].y, 0x00FFFFFF);
		fdf_bline(data, tv[0].x, tv[0]. y,tv[4].x, tv[4].y, 0x00FFFFFF);
		fdf_bline(data, tv[1].x, tv[1]. y,tv[5].x, tv[5].y, 0x00FFFFFF);
		fdf_bline(data, tv[2].x, tv[2]. y,tv[7].x, tv[7].y, 0x00FFFFFF);
		fdf_bline(data, tv[3].x, tv[3]. y,tv[6].x, tv[6].y, 0x00FFFFFF);

	}
}

void fdf_bline(t_data *data,int xi,int yi,int xf,int yf, int color)
{
	double				dx;
	double				dy;
	double				sx;
	double				sy;
	double				err;
	double				e2;

	dx = abs(xf - xi);
	dy = abs(yf - yi);
	sx = (xi < xf) ? 1 : -1;
	sy = (yi < yf) ? 1 : -1;
	err = dx - dy;			
	while (true)
	{
		if (data->put_in_canvas)
			mlx_pixel_put2(data, xi, yi, color);
		else
			mlx_pixel_put(data->ptr_mlx, data->ptr_win, xi, yi, color);
		if ((xi == xf) && (yi == yf)) break;
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

void draw_square(t_data *data,int xi,int yi,int xf,int yf, int color)
{
	int			i;
	int			j;

	i = xi;
	while (i <= xf)
	{
		j = yi;
		while (j <= yf)
		{
			if (data->put_in_canvas)
				mlx_pixel_put2(data, i, j, color);
			else
				mlx_pixel_put(data->ptr_mlx, data->ptr_win, i, j, color);
			j++;
		}
		i++;
	}
}

void			print_buffer(t_data *data)
{
	int			result;

	result = mlx_put_image_to_window (data->mlx_ptr, data->mlx_win,
		data->img[data->front_buffer], 1, 0);
}*/

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
/*
void			print_fdf2(t_data *data)
{
	int			i;
	int			j;
	t_vector3	tv1;
//	t_vector2	pj1;
	char		*s;

	printf("Table des vecteurs\n");
	for (i = 0; i < data->tf->nbline; i++)
	{
		for (j = 0; j < data->tf->nbcol; j++)
		{
			tv1 = data->tf->map[i][j];
			s = dtoa(tv1.x, 2);
			printf("(%s ", s);
			s = dtoa(tv1.y, 2);
			printf("%s ", s);
			s = dtoa(tv1.z * data->coef_elev, 2);
			printf("%s)\t", s);
//			pj1 = project_device(data, tv1, *data->transform_matrix);
		}
		printf("\n");
	}
	printf("\n");
}
*/
void			print_fdf(t_data *data)
{
	int			i;
	int			j;
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
				if (clip_v2(data, &pj1, &pj2))
				{
					printf("i:%d j:%d %le %le %le %le\n", i, j, pj1.x, pj1.y, pj2.x, pj2.y);
					ft_bline(data, pj1.x, pj1.y, pj2.x, pj2.y,0x00FFFFFF);
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
				if (clip_v2(data, &pj1, &pj2))
				{
					printf("i:%d j:%d %le %le %le %le\n", i, j, pj1.x, pj1.y, pj2.x, pj2.y);
					ft_bline(data, pj1.x, pj1.y, pj2.x, pj2.y,0x00FFFFFF);
				}
			}
		}
	}
}

void			render_fdf(t_data *data)
{
//	t_mesh		*mesh;

//	mesh = malloc(sizeof(t_mesh));
//	mesh->position = set_vector3(0, 0, 0);
//	mesh->rotation = set_vector3(0, 0, 0);
//	data->view_matrix = malloc(sizeof(t_matrix));
	*data->view_matrix = look_at_lh_matrix(data->cam->position,
		data->cam->target, up_vector3());
//	data->projection_matrix= malloc(sizeof(t_matrix));
	*data->projection_matrix = perspective_fov_lh_matrix(0.78,
		data->canvas_width / data->canvas_height, 0.01, 1);
//	data->world_matrix = malloc(sizeof(t_matrix));
	*data->world_matrix = multiply_matrix(rot_yaw_pitch_roll_matrix(
		data->scene_rot.y, data->scene_rot.x, data->scene_rot.z),
		translation_matrix(data->scene_pos.x, data->scene_pos.y, 
		data->scene_pos.z));
//	data->transform_matrix = malloc(sizeof(t_matrix));
	*data->transform_matrix = multiply_matrix(*data->world_matrix,
		multiply_matrix(*data->view_matrix, *data->projection_matrix));
}