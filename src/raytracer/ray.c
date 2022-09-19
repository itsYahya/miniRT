#include "raytracer.h"

t_ray	ft_ray(t_tuple origin, t_tuple direction)
{
	return (t_ray){
		origin,
		direction
	};
}

t_ray			ray_transform(t_ray ray, t_matrix transformation_matrix)
{
	return ft_ray(
		matrix_tuple_multiply(transformation_matrix, ray.origin),
		matrix_tuple_multiply(transformation_matrix, ray.direction)
	);
}

t_tuple	ft_position(t_ray r, double t)
{
	return add_tuple(r.origin, multiply_tuple(r.direction, t));
}
