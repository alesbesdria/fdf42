#include "modifpic.h"
/*
void	modifz(t_data *data)
{
	
}

void	modifcolorz(t_data *data)
{
	
}
*/

int		mouseclick(int button, int x, int y, t_data *data)//mouse_hook
{
	int toto;
	toto = data->marg;
	printf("button : %d, x : %d, y : %d\n", button, x, y);
	return (0);
}

int		keymaintain(int keycode, t_data *data)//hook
{
	int toto;
	toto = data->marg;
	printf("keycode : %d\n", keycode);
	return (0);
	
	return (0);
}

int		modifhook(int keycode, t_data *data)//key hook
{
	printf("keycode : %d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(data->ptr_mlx, data->ptr_win);
		exit(0);
	}
	return (0);
/*
	if (keycode == 38)//haut
	{
		
	}
	if (keycode == 40)//bas
	{
		
	}
	if (keycode == 39)//rotation droite
	{
		
	}
	if (keycode == 37)//rotation gauche
	{
		
	}
	if (keycode == 190)//rotation haute .
	{
		
	}
	if (keycode == 188)//rotation basse ,
	{
		
	}
	if (keycode == 32)//modification couleur en boucle barre espace
	{
		
	}
*/
}
