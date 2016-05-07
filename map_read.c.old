#include "map_read.h"

int			**createtable(int nbline, int nbcol)
{
	int		i;
	int		**table1;
	int		*table2;

	table1 = (int **) malloc(sizeof(int*) * nbline);
	table2 = (int *) malloc(sizeof(int) * nbcol * nbline);
	i = 0;
	while  (i < nbline)
	{
		table1[i] = &table2[i * nbcol];
		i++;
	}
	return (table1);
}

void	createmap(t_l *mylist, t_file *mymap)
{
	t_z		*curr;
	int		i;
	int		j;

	curr = mylist->first;
	mymap->map = createtable(mymap->nbline, mymap->nbcol);
	i = mymap->nbline - 1;
	while (i >= 0)
	{
		j = mymap->nbcol - 1;
		while (j >= 0)
		{
			mymap->map[i][j] = curr->value;
//			printf("value : %d j : %d\n", curr->value, j);
			curr = curr->next;
			j--;
		}
		i--;
	}
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
	fd = open("42.fdf", O_RDONLY);
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
//		printf("value : %d\n", curr->value);
		curr = curr->next;
	}
}

//int		main(int argc, char ** argv)
/*
int		main(void)
{
	t_l			*mylist;
	t_file		mymap;
	mylist = initialisation();
	map_read(&mymap, mylist);
	map_print(mylist);
	createtable(mymap.nbline, mymap.nbcol);
	createmap(mylist, &mymap);
	printf("salut\n");
	return (0);
}*/
