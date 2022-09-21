#include "raytracer.h"

double	ft_xangle(t_tuple orientation)
{
	orientation.x = 0.0;
	if (is_equal(orientation, vector(0, 0, 0)))
		return (0.0);
	return -M_PI_2 + atan2(orientation.y, orientation.z);
}

double	ft_zangle(t_tuple orientation)
{
	if (orientation.y == 0 && orientation.z != 0)
		orientation.y = 1;
	orientation.z = 0.0;
	if (is_equal(orientation, vector(0, 0, 0)))
		return (0.0);
	return atan2(orientation.x, orientation.y);
}

t_matrix	orientation_transform(t_tuple coords, t_tuple orientation)
{
	float		z_angle;
	float		x_angle;

	z_angle = ft_zangle(orientation);
	x_angle = ft_xangle(orientation);
	if (fabs(x_angle) < fabs(z_angle))
		return transforms(3,
			translate(coords.x, coords.y, coords.z),
			rotate_z(z_angle),
			rotate_x(x_angle)
		);
	return transforms(3,
		translate(coords.x, coords.y, coords.z),
		rotate_x(x_angle),
		rotate_z(z_angle)
	);
}
