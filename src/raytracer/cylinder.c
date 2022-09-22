#include "raytracer.h"

t_tuple	local_cylinder_normal(t_tuple p, t_tuple eyev)
{
	t_tuple	normal;

	(void)eyev;
	normal = vector(p.x, 0, p.z);
	// if (dot(normal, eyev) < 0)
	// 	return negate_tuple(normal);
	return (normal);
}

# define VALID_Y(y) (y > obj.cy.min_y && y < obj.cy.max_y)

static double	validate_intersections(t_ray r, t_fpair t, t_object obj)
{
	double	y0;
	double	y1;

	if (t._0 > t._1)
		swap(&t._0, &t._1);
	y0 = ft_position(r, t._0).y;
	y1 = ft_position(r, t._1).y;
	if (VALID_Y(y0) && t._0 > 0)
		return (t._0);
	if (VALID_Y(y1))
		return (t._1);
	return (-1);
}

double	local_cylinder_intersect(t_object cy, t_ray r)
{
	t_params	params;
	t_fpair		t;

	params.a = pow(r.direction.x, 2) + pow(r.direction.z, 2);
	if (equal(params.a, 0.0))
		return (-1);
	params.b = 2 * (r.origin.x * r.direction.x + r.origin.z * r.direction.z);
	params.c = pow(r.origin.x, 2) + pow(r.origin.z, 2) - pow(cy.cy.diameter, 2);
	params.desc = pow(params.b, 2) - 4 * params.a * params.c;
	if (params.desc < 0)
		return (-1);
	t._0 = (-params.b - sqrt(params.desc)) / (2 * params.a);
	t._1 = (-params.b + sqrt(params.desc)) / (2 * params.a);
	return (validate_intersections(r, t, cy));
}


void	cylinder_intersect(t_object obj, t_ray ray, t_info *info)
{
	double		t;
	t_tuple		eyev;
	t_ray		transformed_ray;
	t_tuple		local_hitp;

	transformed_ray = ray_transform(ray, inverse(obj.transform));
	t = local_cylinder_intersect(obj, transformed_ray);
	if (t <= 0 || (info->t > 0 && info->t < t))
		return ;
	info->t = t;
	local_hitp = ft_position(transformed_ray, info->t);
	eyev = normalize(negate_tuple(transformed_ray.direction));
	info->color = obj.color;
	info->point = matrix_tuple_multiply(obj.transform, local_hitp);
	info->point.w = 1;
	info->normal = matrix_tuple_multiply(
					ft_transpose(inverse(obj.transform)),
					local_cylinder_normal(local_hitp, eyev)
					);
	info->normal.w = 0;
}
