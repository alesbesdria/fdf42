#include <stdio.h>
#include "mlx.h"

int		main(void)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx 42");
	mlx_pixel_put(mlx, win, 200, 200, 0x00FFFFFF);
	y = 50;
	while (y < 150)
	{
		x = 50;
		while (x < 150)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}

	mlx_hook(win, my_key_funct, 0);
	int		my_key_funct(int keycode, void *param);
	printf("key event %d\n", keycode);
	mlx_loop(mlx);
	return (0);
}
