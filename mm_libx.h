#ifndef MM_LIBX_H
# define MM_LIBX_H
#include "mm_math.h"
#include "mlx.h"

typedef struct	s_data
{
	void	*ptr_mlx;
	void	*ptr_win;
	int		screen_height;
	int		screen_width;
	int		marg;
	int		begin_map_x;
	int		begin_map_y;
	int		width_map;
	int		height_map;
	int		middle_map;
	int		middle_screen_x;
	int		middle_screen_y;
	int		step_x;
	int		step_y;
}				t_data;

typedef struct	s_file
{
	int			nbcol;
	int			nbline;
	t_vector3	**map;
}				t_file;

typedef struct	s_z
{
	int			value;
	struct s_z	*next;
}				t_z;

#endif
