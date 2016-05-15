#include "mm_math.h"
#include "mm_basic.h"

int					color4_to_int(t_color4 tc)
{
	return (((tc.a * 256 + tc.r) * 256 + tc.g) * 256 + tc.b);
}

t_color4			int_to_color4(int color)
{
	t_color4 tc;

	tc.b = color % 256;
	color /= 256;
	tc.g = color % 256;
	color /= 256;
	tc.r = color % 256;
	tc.a = color / 256;
	return (tc);
}

t_color4			new_color4(short r, short g, short b, short a)
{
	t_color4		tc;

	tc.r = r;
	tc.g = g;
	tc.b = b;
	tc.a = a;
	return (tc);
}

t_vector2			new_vector2(double x, double y)
{
	t_vector2		vector2;

	vector2.x = x;
	vector2.y = y;
	return (vector2);
}

double				length_vector2(t_vector2 myvector)
{
	double			length_vector2;

	length_vector2 = sqrt(myvector.x * myvector.x + myvector.y * myvector.y);
	return (length_vector2);
}

t_vector2			normalize_vector2(t_vector2 myvector)
{
	t_vector2		temp;
	double			len;
	double			num;

	len = length_vector2(myvector);
	if (len == 0)
		len = 1;
	num = 1 / len;
	temp.x = myvector.x * num;
	temp.y = myvector.y * num;
	return (temp);
}

t_vector3			subtract_vector3(t_vector3 myvector, t_vector3 other)
{
	t_vector3		temp;

	temp.x = myvector.x - other.x;
	temp.y = myvector.y - other.y;
	temp.z = myvector.z - other.z;
	return (temp);
}

double				length_vector3(t_vector3 myvector)
{
	double			length_vector3;

	length_vector3 = sqrt(myvector.x * myvector.x + myvector.y * myvector.y
		+ myvector.z * myvector.z);
	return (length_vector3);
}

t_vector3			normalize_vector3(t_vector3 myvector)
{
	t_vector3		temp;
	double			len;
	double			num;

	len = length_vector3(myvector);
	if (len == 0)
		len = 1;
	num = 1 / len;
	temp.x = myvector.x * num;
	temp.y = myvector.y * num;
	temp.z = myvector.z * num;
	return (temp);
}

t_vector3			set_vector3(double X, double Y, double Z)
{
	t_vector3		temp;

	temp.x = X;
	temp.y = Y;
	temp.z = Z;
	return (temp);
}

t_vector3			zero_vector3()
{
	return (set_vector3(0, 0, 0));
}

t_vector3			up_vector3()
{
	return (set_vector3(0, 1.0, 0));
}

t_vector3			transform_coord_vector3(t_vector3 vect, t_matrix t)
{
	double			x;
	double			y;
	double			z;
	double			w;
	t_vector3		temp;

	x = (vect.x * t.m[0]) + (vect.y * t.m[4]) + (vect.z * t.m[8]) + t.m[12];
	y = (vect.x * t.m[1]) + (vect.y * t.m[5]) + (vect.z * t.m[9]) + t.m[13];
	z = (vect.x * t.m[2]) + (vect.y * t.m[6]) + (vect.z * t.m[10]) + t.m[14];
	w = (vect.x * t.m[3]) + (vect.y * t.m[7]) + (vect.z * t.m[11]) + t.m[15];
	temp.x = x / w;
	temp.y = y / w;
	temp.z = z / w;
	return (temp);
}

double				dot_vector3(t_vector3 left, t_vector3 right)
{
	return (left.x * right.x + left.y * right.y + left.z * right.z);
}

t_vector3			cross_vector3(t_vector3 left, t_vector3 right)
{
	t_vector3		temp;

	temp.x = left.y * right.z - left.z * right.y;
	temp.y = left.z * right.x - left.x * right.z;
	temp.z = left.x * right.y - left.y * right.x;
	return (temp);
}

t_matrix			multiply_matrix(t_matrix matrix, t_matrix other)
{
	t_matrix		result;

	result.m[0] = matrix.m[0] * other.m[0] + matrix.m[1] * other.m[4] +
		matrix.m[2] * other.m[8] + matrix.m[3] * other.m[12];
	result.m[1] = matrix.m[0] * other.m[1] + matrix.m[1] * other.m[5] +
		matrix.m[2] * other.m[9] + matrix.m[3] * other.m[13];
	result.m[2] = matrix.m[0] * other.m[2] + matrix.m[1] * other.m[6] +
		matrix.m[2] * other.m[10] + matrix.m[3] * other.m[14];
	result.m[3] = matrix.m[0] * other.m[3] + matrix.m[1] * other.m[7] +
		matrix.m[2] * other.m[11] + matrix.m[3] * other.m[15];
	result.m[4] = matrix.m[4] * other.m[0] + matrix.m[5] * other.m[4] +
		matrix.m[6] * other.m[8] + matrix.m[7] * other.m[12];
	result.m[5] = matrix.m[4] * other.m[1] + matrix.m[5] * other.m[5] +
		matrix.m[6] * other.m[9] + matrix.m[7] * other.m[13];
	result.m[6] = matrix.m[4] * other.m[2] + matrix.m[5] * other.m[6] +
		matrix.m[6] * other.m[10] + matrix.m[7] * other.m[14];
	result.m[7] = matrix.m[4] * other.m[3] + matrix.m[5] * other.m[7] +
		matrix.m[6] * other.m[11] + matrix.m[7] * other.m[15];
	result.m[8] = matrix.m[8] * other.m[0] + matrix.m[9] * other.m[4] +
		matrix.m[10] * other.m[8] + matrix.m[11] * other.m[12];
	result.m[9] = matrix.m[8] * other.m[1] + matrix.m[9] * other.m[5] +
		matrix.m[10] * other.m[9] + matrix.m[11] * other.m[13];
	result.m[10] = matrix.m[8] * other.m[2] + matrix.m[9] * other.m[6] +
		matrix.m[10] * other.m[10] + matrix.m[11] * other.m[14];
	result.m[11] = matrix.m[8] * other.m[3] + matrix.m[9] * other.m[7] +
		matrix.m[10] * other.m[11] + matrix.m[11] * other.m[15];
	result.m[12] = matrix.m[12] * other.m[0] + matrix.m[13] * other.m[4] +
		matrix.m[14] * other.m[8] + matrix.m[15] * other.m[12];
	result.m[13] = matrix.m[12] * other.m[1] + matrix.m[13] * other.m[5] +
		matrix.m[14] * other.m[9] + matrix.m[15] * other.m[13];
	result.m[14] = matrix.m[12] * other.m[2] + matrix.m[13] * other.m[6] +
		matrix.m[14] * other.m[10] + matrix.m[15] * other.m[14];
	result.m[15] = matrix.m[12] * other.m[3] + matrix.m[13] * other.m[7] +
		matrix.m[14] * other.m[11] + matrix.m[15] * other.m[15];
	return (result);
}

t_matrix		from_values_matrix(double initialM11, double initialM12,
				double initialM13, double initialM14, double initialM21,
				double initialM22, double initialM23, double initialM24,
				double initialM31, double initialM32, double initialM33,
				double initialM34, double initialM41, double initialM42,
				double initialM43, double initialM44)
{
	t_matrix		result;

	result.m[0] = initialM11;
	result.m[1] = initialM12;
	result.m[2] = initialM13;
	result.m[3] = initialM14;
	result.m[4] = initialM21;
	result.m[5] = initialM22;
	result.m[6] = initialM23;
	result.m[7] = initialM24;
	result.m[8] = initialM31;
	result.m[9] = initialM32;
	result.m[10] = initialM33;
	result.m[11] = initialM34;
	result.m[12] = initialM41;
	result.m[13] = initialM42;
	result.m[14] = initialM43;
	result.m[15] = initialM44;
	return (result);
}

t_matrix		identity_matrix()
{
	return (from_values_matrix(1.0, 0, 0, 0, 0, 1.0, 0, 0, 0, 0, 1.0, 0, 0, 0,
		0, 1.0));
}

t_matrix		zero_matrix()
{
	return (from_values_matrix(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0));
}

t_matrix		rot_x_matrix(double angle)
{
	t_matrix	result;
	double		c;
	double		s;

	result = zero_matrix();
	s = sin(angle);
	c = cos(angle);
	result.m[0] = 1.0;
	result.m[15] = 1.0;
	result.m[5] = c;
	result.m[10] = c;
	result.m[9] = -s;
	result.m[6] = s;
	return (result);
}

t_matrix		rot_y_matrix(double angle)
{
	t_matrix	result;
	double		c;
	double		s;

	result = zero_matrix();
	s = sin(angle);
	c = cos(angle);
	result.m[5] = 1.0;
	result.m[15] = 1.0;
	result.m[0] = c;
	result.m[2] = -s;
	result.m[8] = s;
	result.m[10] = c;
	return (result);
}

t_matrix		rot_z_matrix(double angle)
{
	t_matrix	result;
	double		c;
	double		s;

	result = zero_matrix();
	s = sin(angle);
	c = cos(angle);
	result.m[10] = 1.0;
	result.m[15] = 1.0;
	result.m[0] = c;
	result.m[1] = s;
	result.m[4] = -s;
	result.m[5] = c;
	return (result);
}

t_matrix		rot_yaw_pitch_roll_matrix(double y, double p, double r)
{
	t_matrix	result;

	result = multiply_matrix(multiply_matrix(rot_z_matrix(r), rot_x_matrix(p)),
		rot_y_matrix(y));
	return (result);
}

t_matrix		translation_matrix(double x, double y, double z)
{
	t_matrix	result;

	result = identity_matrix();
	result.m[12] = x;
	result.m[13] = y;
	result.m[14] = z;
	return (result);
}

t_matrix		look_at_lh_matrix(t_vector3 eye, t_vector3 targt, t_vector3 up)
{
	t_vector3	xaxis;
	t_vector3	yaxis;
	t_vector3	zaxis;
	double		ex;
	double		ey;
	double		ez;

	zaxis = subtract_vector3(targt, eye);
	zaxis = normalize_vector3(zaxis);
	xaxis = cross_vector3(up, zaxis);
	xaxis = normalize_vector3(xaxis);
	yaxis = cross_vector3(zaxis, xaxis);
	yaxis = normalize_vector3(yaxis);
	ex = -dot_vector3(xaxis, eye);
	ey = -dot_vector3(yaxis, eye);
	ez = -dot_vector3(zaxis, eye);
	return (from_values_matrix(xaxis.x, yaxis.x, zaxis.x, 0, xaxis.y, yaxis.y,
		zaxis.y, 0, xaxis.z, yaxis.z, zaxis.z, 0, ex, ey, ez, 1));
}

t_matrix		perspective_fov_lh_matrix(double fov, double aspect, double znear, double zfar)
{
	t_matrix	matrix;
	double		tang;

	matrix = zero_matrix();
	tang = 1.0 / (tan(fov * 0.5));
	matrix.m[0] = tang / aspect;
	matrix.m[1] = matrix.m[2] = matrix.m[3] = 0.0;
	matrix.m[5] = tang;
	matrix.m[4] = matrix.m[6] = matrix.m[7] = 0.0;
	matrix.m[8] = matrix.m[9] = 0.0;
	matrix.m[10] = -zfar / (znear - zfar);
	matrix.m[11] = 1.0;
	matrix.m[12] = matrix.m[13] = matrix.m[15] = 0.0;
	matrix.m[14] = (znear * zfar) / (znear - zfar);
	return (matrix);
}
