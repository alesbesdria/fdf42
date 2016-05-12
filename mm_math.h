#ifndef MM_MATH_H
#define MM_MATH_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "libft2.h"
#include "mm_basic.h"

#define pi 3.14159265359

typedef struct		s_vector3
{
	double			x;
	double			y;
	double			z;
}					t_vector3;

typedef struct		s_vector2
{
	double			x;
	double			y;
}					t_vector2;

typedef struct		s_face
{
	double			a;
	double			b;
	double			c;
}					t_face;

typedef struct		s_matrix
{
	double			m[16];
}					t_matrix;

typedef struct		s_mesh
{
	char			*name;
	t_vector3		*vertices;
	t_face			*faces;
	t_vector3		rotation;
	t_vector3		position;
	long long		length;
}					t_mesh;

typedef struct		s_meshes
{
	long long		length;
	t_mesh			**m;
}					t_meshes;

typedef struct		s_color4
{
	short			r;
	short			g;
	short			b;
	short			a;
}					t_color4;

t_color4			new_color4(short r, short g, short b, short a);
t_vector2			new_vector2(double x, double y);
double				length_vector2(t_vector2 myvector);
t_vector2			normalize_vector2(t_vector2 myvector);
double				length_vector3(t_vector3 myvector);
t_vector3			normalize_vector3(t_vector3 myvector);
t_vector3			set_vector3(double X, double Y, double Z);
t_vector3			zero_vector3();
t_vector3			up_vector3();
t_vector3			transform_coord_vector3(t_vector3 vect, t_matrix t);
double				dot_vector3(t_vector3 left, t_vector3 right);
t_vector3			cross_vector3(t_vector3 left, t_vector3 right);
t_matrix			multiply_matrix(t_matrix matrix, t_matrix other);
t_matrix		from_values_matrix(double initialM11, double initialM12,
				double initialM13, double initialM14, double initialM21,
				double initialM22, double initialM23, double initialM24,
				double initialM31, double initialM32, double initialM33,
				double initialM34, double initialM41, double initialM42,
				double initialM43, double initialM44);
t_matrix		identity_matrix();
t_matrix		zero_matrix();
t_matrix		rot_x_matrix(double angle);
t_matrix		rot_y_matrix(double angle);
t_matrix		rot_z_matrix(double angle);
t_matrix		rot_yaw_pitch_roll_matrix(double y, double p, double r);
t_matrix		translation_matrix(double x, double y, double z);
t_matrix		look_at_lh_matrix(t_vector3 eye, t_vector3 targt, t_vector3 up);
t_matrix		perspective_lh_matrix(double width, double height,
				double znear, double zfar);
t_matrix		perspective_fov_lh_matrix(double fov, double aspect, double znear, double zfar);

#endif

