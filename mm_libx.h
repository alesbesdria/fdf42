#ifndef MM_LIBX_H
# define MM_LIBX_H
#include "mm_math.h"
#include "mlx.h"

#define keypressmask (1L << 0)
#define keyreleasemask (1L << 1)
#define buttonpressmask (1L << 2)
#define buttonreleasemask (1L << 3)
#define keypress 2
#define buttonpress 4

typedef struct	s_file
{
	int			nbcol;
	int			nbline;
	t_vector3	**map;
	double		min_elev;
	double		max_elev;
}				t_file;

typedef struct	s_cam
{
	t_vector3	position;
	t_vector3	target;
}				t_cam;

typedef struct	s_palette
{
	t_color4	start_color;
	t_color4	end_color;
	double		start_range;
	double		end_range;
	int			nb_lines;
}				t_palette;

typedef struct	s_data
{
	char		*argv;
	void		*ptr_mlx;
	void		*ptr_win;
	void		*ptr_menu;
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
	t_file		*tf;
	double		coef_elev;
	double		coef_init_elev;
	double		step_elev;
	int			*img[2];
	int			*canvas[2];
	short		back_buffer;
	short		front_buffer;
	int			bpp;
	int			sizeline;
	int			endian;
	t_palette	*palette;
	int			nb_palette;
	double		ratio_cam;
	double		ratio_init_cam;
	double		step_cam;
}				t_data;

typedef struct	s_z
{
	int			value;
	struct s_z	*next;
}				t_z;

int		mlx_pixel_put2(t_data *data, int x, int y, int color);

#endif
