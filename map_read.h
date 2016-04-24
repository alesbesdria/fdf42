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
