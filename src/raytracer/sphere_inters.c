#include "raytracer.h"
#include "algebra.h"

float	get_rs(t_fpair t)
{
	float	rs;

	rs = -1;
	if (t._0 > 0)
		rs = t._0;
	if (t._1 > 0 && (rs == -1 || t._1 < rs))
		rs = t._1;
	return (rs);
}

static void	ft_results(t_params param, t_object obj, t_info *info, t_ray ray)
{
	t_fpair t;
	float	rs;

	t._0 = (-1 * param.b - sqrt(param.desc)) / (2 * param.a);
	t._1 = (-1 * param.b + sqrt(param.desc)) / (2 * param.a);
	rs = get_rs(t);
	if (rs > EPSILON && ((info->t < 0 && rs > EPSILON) || rs < info->t))
	{
		info->t = rs;
		info->color = obj.color;
		info->point = ft_position(ray, info->t);
		info->normal = subst_tuple(info->point, obj.position);
	}
}

void	ft_solve_sphere(const t_ray ray, t_object obj, t_info *info)
{
	t_tuple		vect;
	t_params	param;

	param.a = dot(ray.direction, ray.direction);
	vect = subst_tuple(ray.origin, point(obj.p.x, obj.p.y, obj.p.z));
	param.b = dot(vect, ray.direction)  * 2;
	param.c = dot(vect, vect) - pow(obj.sphere.diameter, 2);
	param.desc = pow(param.b, 2) - 4 * param.a * param.c;
	if (param.desc >= 0 && param.a != 0)
		ft_results(param, obj, info, ray);
}
