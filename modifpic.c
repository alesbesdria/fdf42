#include "modifpic.h"
/*
void	modifz(t_data *data)
{
	
}

void	modifcolorz(t_data *data)
{
	
}
*/

int		mouseclick(int keycode, int x, int y, t_data *data)//mouse_hook
{
	int toto;
	toto = data->marg;
	printf("keycode : %d, x : %d, y : %d\n", keycode, x, y);
	if (keycode == 5)//zoom-
	{
//		data->coef_elev += data->step_elev;
		data->scene_pos.z -= 0.1;
		return (0);
	}
	if (keycode == 4)//zoom+
	{
//		data->coef_elev -= data->step_elev;
		data->scene_pos.z -= 0.1;
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
		data->coef_elev += 0.1;
		return (0);
	}
	if (keycode == 119)//modifhauteur haut w
	{
		data->coef_elev -= 0.1;
		return (0);
	}
/*->my_meshes->m[0]->rotation.x += 0.01;
 * data->my_meshes->m[0]->rotation.y += 0.01;*/
	if (keycode == 38)//rotation haute
	{
		data->scene_rot.x += 0.1;
		return (0);
//		data->scene_rot.y += 0.1;
//		data->scene_rot.z = ;
	}
	if (keycode == 40)//rotation basse
	{
//		data->scene_pos -= 0.1;
		data->scene_rot.x -= 0.1;
		return (0);
//		data->scene_rot.y -= 0.1;
//		data->scene_rot.z = ;
	}
	if (keycode == 39)//rotation droite
	{
//		data->scene_pos = ;
//		data->scene_rot.x += 0.1;
		data->scene_rot.y += 0.1;
		return (0);
//		data->scene_rot.z = ;
	}
	if (keycode == 37)//rotation gauche
	{
//		data->scene_pos = ;
//		data->scene_rot.x -= 0.1;
		data->scene_rot.y -= 0.1;
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
		data->scene_pos.x = 0;
		data->scene_pos.y = 0;
		data->scene_pos.z = 0;
		return (0);
	}
	return (0);
}
