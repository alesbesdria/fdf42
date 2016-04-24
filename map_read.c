//#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>

void		map_read()
{
	int		n;
	int		x;
	int		y;
	int		z;
	int		i;
	int		fd;
	char	*line;
	char	**tab;


	line = NULL;
	fd = open("42.fdf", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		tab = ft_strsplit(line, ' '); //char const *s, char c
		i = 0;
		while (tab[n][i] != '\0')
		{
			while (tab[n][i] != '\0')
			{
				z = ft_atoi(tab[n][i]);
				x = ft_atoi(tab[i]);
				printf("%d\n", x);
//				printf("%s\n", tab[i]);
				i++;
			}
			y = ft_atoi(tab[n]);
				printf("%d\n", y);
			n++;
		}
//		printf("%s\n", line);
	}
	close(fd);
}

//int		main(int argc, char ** argv)
int		main(void)
{
	map_read();
	return (0);
}
