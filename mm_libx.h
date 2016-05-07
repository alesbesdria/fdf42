#ifndef MM_LIBX_H
# define MM_LIBX_H
#include "mm_math.h"
#include "mlx.h"

typedef struct	s_cam
{
	t_vector3	position;
	t_vector3	target;
}				t_cam;

typedef struct	s_data
{
	void		*ptr_mlx;
	void		*ptr_win;
	int			screen_height;
	int			screen_width;
	int			marg;
	int			begin_map_x;
	int			begin_map_y;
	int			width_map;
	int			height_map;
	int			middle_map;
	int			middle_screen_x;
	int			middle_screen_y;
	int			step_x;
	int			step_y;
	int			canvas_width;
	int			canvas_height;
	short		put_in_canvas;
	t_cam		*cam;
	t_vector3	scene_pos;
	t_vector3	scene_rot;
	t_matrix	*view_matrix;
	t_matrix	*projection_matrix;
	t_matrix	*world_matrix;
	t_matrix	*transform_matrix;
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

int		mlx_pixel_put2(t_data *data, int x, int y, int color);

#endif
