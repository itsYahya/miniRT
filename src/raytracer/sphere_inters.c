#include "raytracer.h"
#include "algebra.h"

static void	ft_results(t_params param, t_object sph_obj, t_info *info, t_ray ray)
{
	float	rs;
	t_tuple	center;

	rs = -1 * param.b - sqrt(param.desc);
	rs = rs / (2 * param.a);
	if (rs > EPSILON && ((info->t < 0 && rs > EPSILON) || rs < info->t))
	{
		info->t = rs;
		info->color = sph_obj.color;
		info->point = add_tuple(ray.origin, multiply_tuple(ray.direction, rs));
		center = point(sph_obj.p.x, sph_obj.p.y, sph_obj.p.z);
		info->normal = normalize(subst_tuple(info->point, center));
	}
}

void	ft_solve_sphere(const t_ray ray, t_object sph_obj, t_info *info)
{
	t_tuple		vect;
	t_params	param;

	param.a = dot(ray.direction, ray.direction);
	vect = subst_tuple(ray.origin, point(sph_obj.p.x, sph_obj.p.y, sph_obj.p.z));
	param.b = dot(vect, ray.direction)  * 2;
	param.c = dot(vect, vect) - pow(sph_obj.sphere.diameter, 2);
	param.desc = pow(param.b, 2) - 4 * param.a * param.c;
	if (param.desc >= 0)
		ft_results(param, sph_obj, info, ray);
}
