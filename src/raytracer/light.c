#include "raytracer.h"
#include <stdio.h>

t_tuple			normal_at(t_object object, t_tuple p)
{
	t_tuple normal;

	p = matrix_tuple_multiply(object.transform_matrix, p);
	normal = subst_tuple(p, point(0, 0, 0));
	normal = matrix_tuple_multiply(
					ft_transpose(inverse(object.transform_matrix)),
					normal
					);
	normal.w = 0;
	return (normalize(normal));
}

t_tuple			reflect(t_tuple v, t_tuple normal)
{
	return subst_tuple(v, multiply_tuple(normal, dot(v, normal) * 2));
}

t_light	point_light(t_tuple position, t_color intensity)
{
	return (t_light){position, intensity};
}

// t_tuple	ft_lighting(t_material material, t_light light, t_tuple position,
// 			t_tuple eyev, t_tuple normalv)
// {
// 	// TODO: implement
// }
