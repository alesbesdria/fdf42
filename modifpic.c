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
	return (0);
}

int		keymaintain(int keycode, t_data *data)//hook
{
	int toto;
	toto = data->marg;
	printf("%d\n", keycode);
	return (0);
	
	return (0);
}

int		modifhook(int keycode, t_data *data)//key hook
{
	printf("%d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(data->ptr_mlx, data->ptr_win);
		exit(0);
	}
	return (0);
/*
	if (keycode == 5)//zoom-
	{
		
	}
	if (keycode == 4)//zoom+
	{
		
	}
	if (keycode == 38)//rotation haute
	{
		
	}
	if (keycode == 40)//rotation basse
	{
		
	}
	if (keycode == 39)//rotation droite
	{
		
	}
	if (keycode == 37)//rotation gauche
	{
		
	}
*/
}
