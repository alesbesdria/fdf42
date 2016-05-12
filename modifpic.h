#ifndef MODIFPIC_H
#define MODIFPIC_H
#include "mm_libx.h"

int	modifhook(int keycode, t_data *data);
int	mouseclick(int keycode, int x, int y, t_data *data);
int	keymaintain(int keycode, t_data *data);

#endif
