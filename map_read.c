//#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#include "map_read.h"
#include "get_next_line.h"

void		map_read(t_file *mymap, t_l *mylist)
{
	t_z		*curr;
	int		x;
	int		y;
	int		z;
	int		fd;
	char	*line;
	char	**tab;

	y = 0;
	line = NULL;
	fd = open("maptestlili.fdf", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		tab = ft_strsplit(line, ' ');
		x = 0;
		while (tab[x] != 0)
		{
			z = ft_atoi(tab[x]);
			curr = malloc(sizeof(t_z));
			curr->value = z;
			curr->next = mylist->first;
			mylist->first = curr;
			x++;
		}
		y++;
		free(line);
	}
	mymap->nbcol = y;
	mymap->nbline = x;
	close(fd);
}

void	map_print(t_file *mymap, t_l *mylist)
{
	t_z	*curr;
	curr = mylist->first;
	while (curr->next != NULL)
	{
		printf("value : %d\n", curr->value);
		curr = curr->next;
	}
}

//int		main(int argc, char ** argv)
int		main(void)
{
	t_l			*mylist;
	t_file		*mymap;
	mymap = NULL;
	mylist = initialisation();
	map_read(mymap, mylist);
	map_print(mymap, mylist);
	return (0);
}
