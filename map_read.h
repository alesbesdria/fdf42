#ifndef MAP_READ_H
# define MAP_READ_H
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
#include "mm_math.h"
#include "mm_libx.h"

t_vector3	**createtable(int nbline, int nbcol);
void		createmap(t_l *mylist, t_file *mymap);
void		map_read(int fd, t_file *mymap, t_l *mylist);
void		map_print(t_l *mylist);

#endif
