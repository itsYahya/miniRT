#include "raytracer.h"

t_ray	ray(t_tuple origin, t_tuple direction)
{
	return (t_ray){
		origin,
		direction
	};
}

t_tuple	position(t_ray r, float t)
{
	return add_tuple(r.origin, multiply_tuple(r.direction, t));
}
