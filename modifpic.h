#ifndef MODIFPIC_H
#define MODIFPIC_H
#include "mm_libx.h"
#include "mm_graph.h"

int			modifhook(int keycode, t_data *data);
int			mouseclick(int keycode, int x, int y, t_data *data);
int			keymaintain(int keycode, t_data *data);
int			modifcolor(int xi, int yi, int xf, int yf,
				int save_xi, int save_yi);

#endif
