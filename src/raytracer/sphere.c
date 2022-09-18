# include "raytracer.h"

t_object ft_sphere()
{
	t_object	object;

	object.transform = IDENTITY_MATRIX;
	object.material = ft_material();
	object.type = E_SPHERE;
	object.inverted_transform = inverse(object.transform);
	return (object);
}

t_tuple			sphere_normal(t_object object, t_tuple p)
{
	t_tuple normal;

	p = matrix_tuple_multiply(object.transform, p);
	normal = subst_tuple(p, point(0, 0, 0));
	normal = matrix_tuple_multiply(
					ft_transpose(inverse(object.transform)),
					normal
					);
	normal.w = 0;
	return (normalize(normal));
}

t_xs		intersect_sphere(t_object object, t_ray ray)
{
	struct
	{
		float	a;
		float	b;
		float	c;
	}		f;
	t_tuple			sphere_to_ray;
	float			discripminant;
	t_inter	t1;
	t_inter	t2;

	ray = ray_transform(ray, inverse(object.transform));
	sphere_to_ray = subst_tuple(ray.origin, point(0, 0, 0));
	f.a = dot(ray.direction, ray.direction);
	f.b = 2 * dot(ray.direction, sphere_to_ray);
	f.c = dot(sphere_to_ray, sphere_to_ray) - 1;
	discripminant = pow(f.b, 2) - 4 * f.a * f.c;
	if (discripminant < 0)
		return (t_xs){0};
	t1 = ft_inter((-f.b - sqrt(discripminant)) / (2 * f.a), object);
	t2 = ft_inter((-f.b + sqrt(discripminant)) / (2 * f.a), object);
	if (discripminant == 0)
		return ft_inters(1, t1);
	return ft_inters(2, t1, t2);
}
