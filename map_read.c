//#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#include "map_read.h"
#include "get_next_line.h"

int			**createtable(int nbline, int nbcol)
{
	int		i;
	int		**table1;
	int		*table2;
	printf("a\n");

	table1 = (int **) malloc(sizeof(int*) * nbline);
	table2 = (int *) malloc(sizeof(int) * nbcol * nbline);
	printf("b\n");
	i = 0;
	while  (i < nbline)
	{
		printf("c\n");
		table1[i] = &table2[i * nbcol];
		printf("nb column : %d\n", nbcol);
		i++;
	}
	printf("e\n");
	return (table1);
}

void		map_read(t_file *mymap, t_l *mylist)
{
	t_z		*curr;
	int		x;
	int		y;
	int		z;
	int		fd;
	char	*line;
	char	**tab;
// colonne = x, ligne = y;
	y = 0;
	line = NULL;
	fd = open("maptestlili.fdf", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		tab = ft_strsplit(line, ' ');
		x = 0;
		while (tab[x] != 0)
		{
			curr = malloc(sizeof(t_z));
			z = ft_atoi(tab[x]);
			curr->value = z;
			curr->next = mylist->first;
			mylist->first = curr;
			x++;
		}
		y++;
		free(line);
	}
	mymap->map = createtable(y, x);
	mymap->nbcol = x;
	mymap->nbline = y;
	close(fd);
}

void	map_print(t_l *mylist)
{
	t_z	*curr;
	curr = mylist->first;
	while (curr != NULL)
	{
		printf("value : %d\n", curr->value);
		curr = curr->next;
	}
}

//int		main(int argc, char ** argv)
int		main(void)
{
	t_l			*mylist;
	t_file		mymap;
	mylist = initialisation();
	map_read(&mymap, mylist);
	map_print(mylist);
	return (0);
}
