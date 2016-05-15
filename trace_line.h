#ifndef TRACE_LINE_H
# define TRACE_LINE_H
//#include "mm_libx.h"
#include "modifpic.h"

void	ft_bline(t_data *data, int xi, int yi, int xf, int yf, int color);
void	ft_bline_color(t_data *data, int xi, int yi, int xf, int yf, double alt1, double alt2);
void	place_map(t_data *data);
void	step(t_data *data, t_file *mymap);
void	draw_grid(t_data *data, t_file *mymap);

#endif
