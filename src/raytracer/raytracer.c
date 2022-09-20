#include "raytracer.h"
#include <stdarg.h>
#include <stdlib.h>
#include "utils.h"
#include "pair.h"

t_inter	ft_hit(t_xs xs)
{
	t_inter	inter;
	t_inter	visible_inter;
	int		i;

	visible_inter = (t_inter){-1, { .type = E_INVALID }};
	i = -1;
	while (++i < xs.count)
	{
		inter = xs.inters[i];
		if (inter.t > 0 && (visible_inter.t < 0 || inter.t < visible_inter.t))
			visible_inter = inter;
	}
	return (visible_inter);
}

t_xs	intersect(t_object object, t_ray ray)
{
	t_xs	xs;

	xs = (t_xs){0, NULL};

	ray = ray_transform(ray, inverse(object.transform));
	if (object.type == E_SPHERE)
		xs = local_sphere_intersect(object, ray);
	else {
		printf("object type undefined\n");
	}
	return (xs);
}

t_tuple	normal_at(t_object object, t_tuple p)
{
	t_tuple normal;

	normal = vector(0, 0, 0);
	p = matrix_tuple_multiply(object.inverted_transform, p);
	if (object.type == E_SPHERE) {
		normal = local_sphere_normal(p);
	} else {
		printf("object type undefined\n");
		return (normal);
	}
	normal = matrix_tuple_multiply(object.transpose_matrix, normal);
	normal.w = 0;
	return (normalize(normal));
}
