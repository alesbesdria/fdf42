#include "map_read.h"

t_vector3			**createtable(int nbline, int nbcol)
{
	int		i;
	t_vector3		**table1;
	t_vector3		*table2;

	table1 = (t_vector3 **) malloc(sizeof(void *) * nbline);
	table2 = (t_vector3 *) malloc(sizeof(t_vector3) * nbcol * nbline);
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
	double	center_x;
	double	center_y;
	int		i;
	int		j;

	mymap->min_elev = 1e70;
	mymap->max_elev = -1e70;
	curr = mylist->first;
	mymap->map = createtable(mymap->nbline, mymap->nbcol);
	center_x = (float) (mymap->nbcol - 1) / 2;
	center_y = (float) (mymap->nbline - 1) / 2;
	i = mymap->nbline - 1;
	while (i >= 0)
	{
		j = mymap->nbcol - 1;
		while (j >= 0)
		{
			if (mymap->min_elev > curr->value)
				mymap->min_elev = curr->value;
			if (mymap->max_elev < curr->value)
				mymap->max_elev = curr->value;
			mymap->map[i][j] = set_vector3(center_x - j, i - center_y, curr->value);
//			printf("value : %d j : %d\n", curr->value, j);
			curr = curr->next;
			j--;
		}
		i--;
	}
}

void		map_read(int fd, t_file *mymap, t_l *mylist)
{
	t_z		*curr;
	int		x;
	int		y;
	int		z;
	char	*line;
	char	**tab;
// colonne = x, ligne = y;
	y = 0;
	line = NULL;
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
	createmap(mylist, mymap);
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
