# include "raytracer.h"

t_object	ft_sphere()
{
	return (new_sphere(
		point(0, 0, 0),
		1,
		ft_color(1, 1, 1)
		));
}

t_object new_sphere(t_tuple coords, float radius, t_color color)
{
	t_object	object;
	t_matrix	transform;

	object.material = ft_material();
	object.material.color = color;
	object.type = E_SPHERE;
	transform = transforms(2,
		translate(coords.x, coords.y, coords.z),
		scale(radius, radius, radius));
	set_transform(&object, transform);
	return (object);
}

t_tuple			sphere_normal(t_object object, t_tuple p)
{
	t_tuple normal;

	p = matrix_tuple_multiply(object.inverted_transform, p);
	normal = subst_tuple(p, point(0, 0, 0));
	normal = matrix_tuple_multiply(object.transpose_matrix, normal);
	normal.w = 0;
	return (normalize(normal));
}

t_xs		intersect_sphere(t_object object, t_ray ray)
{
	t_params	param;
	t_tuple		sphere_to_ray;
	t_inter		t[2];

	ray = ray_transform(ray, inverse(object.transform));
	sphere_to_ray = subst_tuple(ray.origin, point(0, 0, 0));
	param.a = dot(ray.direction, ray.direction);
	param.b = 2 * dot(ray.direction, sphere_to_ray);
	param.c = dot(sphere_to_ray, sphere_to_ray) - 1;
	param.desc = pow(param.b, 2) - 4 * param.a * param.c;
	if (param.desc < 0)
		return (t_xs){0, NULL};
	t[0] = ft_inter((-param.b - sqrt(param.desc)) / (2 * param.a), object);
	t[1] = ft_inter((-param.b + sqrt(param.desc)) / (2 * param.a), object);
	return ft_inters(2, t[0], t[1]);
}
