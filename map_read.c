//#include "libft.h"
#include <fcntl.h>
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
		tab = ft_strsplit(line, ' '); //char const *s, char c
		x = 0;
		while (tab[x] != 0)
		{
			z = ft_atoi(tab[x]);
			curr = malloc(sizeof(t_z));
			curr->value = z;
			curr->next = mylist->first;
			mylist->first = curr;

//			printf("x = %d\n", x);
//			printf("z = %d\n", z);
//			printf("%s\n", tab[x]);
			x++;
		}
//		printf("y = %d\n", y);
//		printf("%s\n", line);
		y++;
		free(line);
	}
	mymap->nbcol = y;
	mymap->nbline = x;
	close(fd);
}

//int		main(int argc, char ** argv)
int		main(void)
{
	t_l			*mylist;
	t_file		*mymap;
	mylist = initialisation();
	map_read(mymap, mylist);
	return (0);
}
