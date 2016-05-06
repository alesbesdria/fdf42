#ifndef FDF_H
# define FDF_H
#include "map_read.h"
#include "mlx.h"

typedef struct	s_data
{
	void	*ptr_mlx;
	void	*ptr_win;
	int		screen_height;
	int		screen_width;
	int		marg;
	int		begin_map_x;
	int		begin_map_y;
	int		width_map;
	int		height_map;
	int		middle_map;
	int		middle_screen_x;
	int		middle_screen_y;
	int		step_x;
	int		step_y;
}				t_data;

void	ft_line(t_data *data, int xi, int yi, int xf, int yf, int color);
void	ft_bline(t_data *data, int xi, int yi, int xf, int yf, int color);
void	place_map(t_data *data, t_file *mymap);
//void	line_trace(t_l *mylist, t_file *mymap);

#endif
