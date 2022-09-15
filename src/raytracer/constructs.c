#include "raytracer.h"

t_tuple	ft_position(t_ray r, float t)
{
	return add_tuple(r.origin, multiply_tuple(r.direction, t));
}
