#include "mm_libx.h"

int		mlx_pixel_put2(t_data *data, int x, int y, int color)
{
	if ((x >= 0) && (y >= 0) && (x < data->canvas_width) && (y < data->canvas_height))
	{
		mlx_pixel_put(data->ptr_mlx, data->ptr_win, x, y, color);
	}
	return (0);
}
