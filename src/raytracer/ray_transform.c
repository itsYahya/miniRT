#include "raytracer.h"

t_ray			ft_transform(t_ray ray, t_matrix transformation_matrix)
{
	return ft_ray(
		matrix_tuple_multiply(transformation_matrix, ray.origin),
		matrix_tuple_multiply(transformation_matrix, ray.direction)
	);
}

void			set_transform(t_object *object, t_matrix matrix)
{
	if (! object)
		return ;
	object->transform_matrix = matrix;
}
