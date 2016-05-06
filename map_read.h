#ifndef MAP_READ_H
# define MAP_READ_H
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

typedef struct	s_file
{
	int			nbcol;
	int			nbline;
	int			**map;
}				t_file;

typedef struct	s_z
{
	int			value;
	struct s_z	*next;
}				t_z;

int		**createtable(int nbline, int nbcol);
void	createmap(t_l *mylist, t_file *mymap);
void	map_read(t_file *mymap, t_l *mylist);
void	map_print(t_l *mylist);

#endif
