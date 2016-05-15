#include "modifpic.h"
/*
int		modifcolor(int xi, int yi, int xf, int yf, int save_xi, int save_yi)
{
	t_color4	*t_c;
	t_vector3	t_v;
	double	color;
	int		i;
	int		j;
	int		start;
	int		len_vector;

	i = 0;
	j = 0;
	len_vector = length_vector3(t_v);
	start = len_vector / 4;
	t_c->a = pow(0x00, 3);
	t_c->r = pow(i, 2);
	t_c->g = pow(i, 1);
	t_c->b = pow(i, 0);
	sqrt()
	while (i <= 256)
	{
		while (j < start)
		{
			start += 256 / 100;
			t_c->r = pow(i, 2);
			t_c->g = pow(i, 1);
			t_c->b = pow(i, 0);
			j++;
		}
		i += 256 / 4;
		i++;
		//longueur vertex /4 ou /6
//		mlx_pixel_put2(data, t_v.x, t_v.y, color);
	}
	return (color);
}*/

int		mouseclick(int keycode, int x, int y, t_data *data)//mouse_hook
{
	int toto;
	toto = data->marg;
	printf("keycode : %d, x : %d, y : %d\n", keycode, x, y);
	if (keycode == 5)//zoom-
	{
//		data->coef_elev += data->step_elev;
		clear_screen(data);
		data->scene_pos.z -= 2;
		render_fdf(data);
		print_fdf(data);
		return (0);
	}
	if (keycode == 4)//zoom+
	{
//		data->coef_elev -= data->step_elev;
		clear_screen(data);
		data->scene_pos.z += 2;
		render_fdf(data);
		print_fdf(data);
		return (0);
	}
	return (0);
}

int		keymaintain(int keycode, t_data *data)//hook
{
	int toto;
	toto = data->marg;
	printf("%d\n", keycode);

	if (keycode == 115)//modifhauteur bas s
	{
		clear_screen(data);
		data->coef_elev += 0.1;
		render_fdf(data);
		print_fdf(data);
		return (0);
	}
	if (keycode == 119)//modifhauteur haut w
	{
		clear_screen(data);
		data->coef_elev -= 0.1;
		render_fdf(data);
		print_fdf(data);
		return (0);
	}
//->my_meshes->m[0]->rotation.x += 0.01;
// data->my_meshes->m[0]->rotation.y += 0.01;
	if (keycode == 65362)//rotation haute
	{
		clear_screen(data);
		data->scene_rot.x += .1;
		render_fdf(data);
		print_fdf(data);
		return (0);
//		data->scene_rot.y += 0.1;
//		data->scene_rot.z = ;
	}
	if (keycode == 65364)//rotation basse
	{
		clear_screen(data);
//		data->scene_pos -= 0.1;
		data->scene_rot.x -= .1;
		render_fdf(data);
		print_fdf(data);
		return (0);
//		data->scene_rot.y -= 0.1;
//		data->scene_rot.z = ;
	}
	if (keycode == 65363)//rotation droite
	{
//		data->scene_pos = ;
//		data->scene_rot.x += 0.1;
		clear_screen(data);
		data->scene_rot.y += .1;
		render_fdf(data);
		print_fdf(data);
		return (0);
//		data->scene_rot.z = ;
	}
	if (keycode == 65361)//rotation gauche
	{
//		data->scene_pos = ;
//		data->scene_rot.x -= 0.1;
		clear_screen(data);
		data->scene_rot.y -= .1;
		render_fdf(data);
		print_fdf(data);
		return (0);
//		data->scene_rot.z = ;
	}
	return (0);
}

int		modifhook(int keycode, t_data *data)//key hook
{
	printf("%d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(data->ptr_mlx, data->ptr_win);
		exit(0);
		return (0);
	}
	if (keycode == 32)//barre espace retour a la normale
	{
		clear_screen(data);
		data->scene_pos.x = 0;
		data->scene_pos.y = 0;
		data->scene_pos.z = 0;
		render_fdf(data);
		print_fdf(data);
		return (0);
	}
	return (0);
}
