#include "raytracer.h"

void	set_transform(t_object *obj, t_matrix transform)
{
	obj->transform = transform;
	obj->inverted_transform = inverse(obj->transform);
	obj->transpose_matrix = ft_transpose(obj->inverted_transform);
}
