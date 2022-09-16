#include "raytracer.h"

static void	ft_set_info(t_info *info, t_object obj, t_ray ray, t_tuple eyev)
{
	t_tuple	hitpoint;

	hitpoint = add_tuple(ray.origin, multiply_tuple(ray.direction, info->t));
	info->color.raw = obj.color;
	info->normal = subst_tuple(hitpoint, point(0, 0, hitpoint.z));
	info->normal = matrix_tuple_multiply(
					ft_transpose(inverse(obj.transform)),
					info->normal
					);
	info->normal.w = 0;
	info->normal = normalize(info->normal);
	if (dot(info->normal, eyev) < 0)
		info->normal = negate_tuple(info->normal);
}

static bool	isvalid_intersection(t_ray r, float t)
{
	float	z;

	z = ft_position(r, t).z;
	return (t > 0 && fabs(z) <= 1);
}

static float	cy_local_intersect(t_ray ray)
{
	t_params	params;
	float		disc;
	t_fpair		t;
	float		mint;

	mint = -1;
	params.a = pow(ray.direction.x, 2) + pow(ray.direction.y, 2);
	if (equal(params.a, 0.0f))
		return (-2);
	params.b = 2 * (ray.origin.x * ray.direction.x + ray.origin.y * ray.direction.y);
	params.c = pow(ray.origin.x, 2) + pow(ray.origin.y, 2) - 1;
	disc = pow(params.b, 2) - 4 * params.a * params.c;
	if (disc < 0)
		return (-3);
	t._0 = (-params.b + sqrt(disc)) / (2 * params.a);
	t._1 = (-params.b - sqrt(disc)) / (2 * params.a);
	if (isvalid_intersection(ray, t._0))
		mint = t._0;
	if (isvalid_intersection(ray, t._1) && (mint < 0 || t._1 < mint))
		mint = t._1;
	return (mint);
}

void	cylinder_intersect(t_object obj, t_ray ray, t_info *info)
{
	float		t;
	t_tuple		eyev;

	eyev = negate_tuple(ray.direction);
	ray = ray_transform(ray, inverse(obj.transform));
	t = cy_local_intersect(ray);
	if (t > 0 && (info->t < 0 || t < info->t))
	{
		info->t = t;
		ft_set_info(info, obj, ray, eyev);
	}
}
