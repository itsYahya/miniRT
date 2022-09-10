#include "canvas.h"
#include "pair.h"
#include <stdio.h>
#include "ray.h"
#include "objects.h"
#include "randerer.h"

typedef struct s_paramerers
{
	float	a;
	float	b;
	float	c;
	float	delta;
}	t_param;

static void	ft_results(t_param param, t_sphere sphere, t_info *info, t_ray ray)
{
	float	rs;
	t_tuple	center;
	
	rs = -1 * param.b - sqrt(param.delta);
	rs = rs / (2 * param.a);
	if (rs > 0 && (info->t < 0 || rs < info->t))
	{
		info->t = rs;
		info->color.raw = sphere.color;
		info->point = add_tuple(ray.origin, multiply_tuple(ray.direction, rs));
		center = point(sphere.center.x, sphere.center.y, sphere.center.z);
		info->normal = normalize(subst_tuple(info->point, center));
	}
}	

void	ft_solve_sphere(const t_ray ray, t_sphere sphere, t_info *info)
{
	t_tuple	vect;
	t_param param;

	param.a = dot(ray.direction, ray.direction);
	vect = subst_tuple(ray.origin, point(sphere.center.x, sphere.center.y, sphere.center.z));
	param.b = dot(vect, ray.direction)  * 2;
	param.c = dot(vect, vect) - pow(sphere.diameter, 2);
	param.delta = pow(param.b, 2) - 4 * param.a * param.c;
	if (param.delta >= 0)
		ft_results(param, sphere, info, ray);
}
