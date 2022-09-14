#include "raytracer.h"

static double	ft_degrees_to_radians(const float angel)
{
	return (angel * M_PI / 180);
}

t_vcamera	ft_setup_camera(const t_camera camera)
{
	t_vcamera c;
	c.ar = (float)WIDTH / (float)HEIGHT;
	c.h = tan(ft_degrees_to_radians(camera.fov/2));
	c.w = c.h * c.ar;
	c.origin = point(camera.coordinates.x, camera.coordinates.y, camera.coordinates.z);
	c.forward = vector(camera.orientation_vect.x, camera.orientation_vect.y, camera.orientation_vect.z);
	c.up = normalize(cross(c.forward, vector(0, 1, 0)));
	c.right = normalize(cross(c.forward, c.up));
	return (c);
}
