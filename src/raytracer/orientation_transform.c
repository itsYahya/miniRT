#include "raytracer.h"

double	ft_xangle(t_tuple orientation)
{
	return -atan2(orientation.z, orientation.y);
}

double	ft_zangle(t_tuple orientation, double x_angle)
{
	orientation = matrix_tuple_multiply(rotate_x(x_angle), orientation);
	return atan2(orientation.x, orientation.y);
}

t_matrix	orientation_transform(t_tuple coords, t_tuple orientation)
{
	double	z_angle;
	double	x_angle;

	x_angle = ft_xangle(orientation);
	z_angle = ft_zangle(orientation, x_angle);
	t_matrix rotation = transforms(2,
		rotate_z(z_angle),
		rotate_x(x_angle)
	);
	return matrix_multiply(translate(coords.x, coords.y, coords.z), inverse(rotation));
}
