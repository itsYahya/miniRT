#include "raytracer.h"

t_tuple	local_cone_normal(t_tuple p)
{
	double	y;

	y = sqrt(pow(p.x, 2) + pow(p.z, 2));
	if (p.y > 0)
		y *= -1;
	return (vector(p.x, y, p.z));
}

static double	local_cone_intersect(t_object obj, t_ray r)
{
	t_params	params;
	t_fpair		t;

	params.a = pow(r.direction.x, 2) - pow(r.direction.y, 2) + pow(r.direction.z, 2);
	params.b = 2 * (r.origin.x * r.direction.x - r.origin.y * r.direction.y + r.origin.z * r.direction.z);
	params.c = pow(r.origin.x, 2) - pow(r.origin.y, 2) + pow(r.origin.z, 2);

	if (params.a == 0.0 || params.b == 0.0)
		return (-1);
	if (params.a == 0.0)
		return (-params.c / params.b);
	params.desc = pow(params.b, 2) - 4 * params.a * params.c;
	if (params.desc < 0)
		return (-1);
	t._0 = (-params.b - sqrt(params.desc)) / (2 * params.a);
	t._1 = (-params.b + sqrt(params.desc)) / (2 * params.a);
	return cy_validate_local_inters(r, t, obj);
}

void	cone_intersect(t_object obj, t_ray ray, t_info *info)
{
	double		t;
	t_ray		transformed_ray;
	t_tuple		local_hitp;

	transformed_ray = ray_transform(ray, obj.inverted_transform);
	t = local_cone_intersect(obj, transformed_ray);
	if (t < EPSILON_2 || (info->t > EPSILON_2 && info->t < t))
		return ;
	info->t = t;
	local_hitp = ft_position(transformed_ray, info->t);
	info->object = obj;
	info->point = matrix_tuple_multiply(obj.transform, local_hitp);
	info->point.w = 1;
	info->normal = matrix_tuple_multiply(obj.transpose, local_cone_normal(local_hitp));
	info->normal.w = 0;
}
