#include "modifpic.h"
#include <unistd.h>

void		menu(t_data *data)
{
	int	increment;
	int	pas;

	increment = 1;
	pas = 12;
//	ft_bline(data, 801, 0, 801, 1000, 0x0026FFFB);
	mlx_string_put(data->ptr_mlx, data->ptr_win, data->screen_width - 150,
	pas * increment++, 0X00269DFF, "   M E N U    ");
		increment++;
	mlx_string_put(data->ptr_mlx, data->ptr_win, data->screen_width - 175,
	pas * increment++, 0X0026FFFB, "Zoom+ : Souris Avant");
		increment++;
	mlx_string_put(data->ptr_mlx, data->ptr_win, data->screen_width - 175,
	pas * increment++, 0x0026FFFB, "Zoom- : Souris Arriere");
		increment++;
	mlx_string_put(data->ptr_mlx, data->ptr_win, data->screen_width - 175,
	pas * increment++, 0x0026FFFB, "Rot. Haut : Fleche Haut");
		increment++;
	mlx_string_put(data->ptr_mlx, data->ptr_win, data->screen_width - 175,
	pas * increment++, 0x0026FFFB, "Rot. Bas : Fleche Bas");
		increment++;
	mlx_string_put(data->ptr_mlx, data->ptr_win, data->screen_width - 175,
	pas * increment++, 0x0026FFFB, "Rot. Gauche : Fleche Gauche");
		increment++;
	mlx_string_put(data->ptr_mlx, data->ptr_win, data->screen_width - 175,
	pas * increment++, 0x0026FFFB, "Rot. Droite : Fleche Droite");
		increment++;
	mlx_string_put(data->ptr_mlx, data->ptr_win, data->screen_width - 175,
	pas * increment++, 0x0026FFFB, "Modif. Alt. Haut : W");
		increment++;
	mlx_string_put(data->ptr_mlx, data->ptr_win, data->screen_width - 175,
	pas * increment++, 0x0026FFFB, "Modif. Alt. Bas : S");
		increment++;
}

int		modifcolor(t_data *data, double altitude)
{
	int			color;
	double		proportion;
	t_color4	s_c;
	t_color4	e_c;
	t_color4	f_c;
	double		diff_range;
	double		max_diff_range;
	int			i;

	data->nb_palette = 6;
	data->palette = malloc(sizeof(t_palette) * data->nb_palette);
	
	data->palette[0].start_color = new_color4(0, 0xFF, 0x00, 0xFF);
	data->palette[0].end_color = new_color4(0, 0xFF, 0x00, 0x00);
	data->palette[0].start_range = 0;
	data->palette[0].end_range = 0.333;
	data->palette[1].start_color = new_color4(0, 0xFF, 0x00, 0x00);
	data->palette[1].end_color = new_color4(0, 0xFF, 0xFF, 0x00);
	data->palette[1].start_range = 0.333;
	data->palette[1].end_range = 0.666;
	data->palette[2].start_color = new_color4(0, 0xFF, 0xFF, 0x00);
	data->palette[2].end_color = new_color4(0, 0x00, 0xFF, 0x00);
	data->palette[2].start_range = 0.666;
	data->palette[2].end_range = 1;
	data->palette[3].start_color = new_color4(0, 0x00, 0xFF, 0x00);
	data->palette[3].end_color = new_color4(0, 0x00, 0xFF, 0xFF);
	data->palette[3].start_range = 1;
	data->palette[3].end_range = 1.333;
	data->palette[4].start_color = new_color4(0, 0x00, 0xFF, 0xFF);
	data->palette[4].end_color = new_color4(0, 0x00, 0x00, 0xFF);
	data->palette[4].start_range = 1.333;
	data->palette[4].end_range = 1.666;
	data->palette[5].start_color = new_color4(0, 0x00, 0x00, 0xFF);
	data->palette[5].end_color = new_color4(0, 0xFF, 0X00, 0xFF);
	data->palette[5].start_range = 1.666;
	data->palette[5].end_range = 2;
	/*
	data->palette[0].start_color = new_color4(0x00, 0x00, 0x00, 0x40);
	data->palette[0].end_color = new_color4(0x00, 0x00, 0x00, 0xFF);
	data->palette[0].start_range = 0;
	data->palette[0].end_range = 0.333;
	data->palette[1].start_color = new_color4(0x00, 0x00, 0x40, 0x00);
	data->palette[1].end_color = new_color4(0x00, 0x00, 0xFF, 0x00);
	data->palette[1].start_range = 0.333;
	data->palette[1].end_range = 0.666;
	data->palette[2].start_color = new_color4(0x00, 0x40, 0x00, 0x00);
	data->palette[2].end_color = new_color4(0x00, 0xFF, 0x00, 0x00);
	data->palette[2].start_range = 0.666;
	data->palette[2].end_range = 1;*/
	max_diff_range = data->palette[data->nb_palette - 1].end_range -
		data->palette[0].start_range;
	i = 0;
	while (i < data->nb_palette)
	{
		data->palette[i].start_range /= max_diff_range;
		data->palette[i].end_range /= max_diff_range;
		i++;
	}
//	start_color = 0x00404040;
//	end_color = 0x00FFFFFF;
//	s_c = int_to_color4(data->palette[i].start_color);
//	e_c = int_to_color4(data->palette[i].end_color);
	proportion = ((altitude - data->tf->min_elev) /
		(data->tf->max_elev - data->tf->min_elev));
	i = 0;
	while (i < data->nb_palette)
	{
		if ((proportion >= data->palette[i].start_range) && 
				(proportion <= data->palette[i].end_range))
			break;
		i++;
	}
//	printf("%d %le - ",i,altitude);
	s_c = data->palette[i].start_color;
	e_c = data->palette[i].end_color;;
	diff_range = data->palette[i].end_range - data->palette[i].start_range;
	proportion = (proportion - data->palette[i].start_range) / diff_range;
	f_c.r = s_c.r + ((e_c.r - s_c.r) * proportion);
	f_c.g = s_c.g + ((e_c.g - s_c.g) * proportion);
	f_c.b = s_c.b + ((e_c.b - s_c.b) * proportion);
	f_c.a = s_c.a + ((e_c.a - s_c.a) * proportion);
	color = color4_to_int(f_c);
	return (color);
}

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

	if (keycode == 119)//modifhauteur bas s
	{
		clear_screen(data);
		data->coef_elev += 0.1;
		render_fdf(data);
		print_fdf(data);
		return (0);
	}
	if (keycode == 115)//modifhauteur haut w
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
