#include "raytracer.h"
#include <math.h>

void	ft_solve_plane(t_ray ray, t_plane plane, t_info *info)
{
	t_tuple	p_normal;
	t_tuple	p_point;
	float	dot1;
	float	dot2;
	float	t;

	p_point = point(plane.point.x, plane.point.y, plane.point.z);
	p_normal = vector(plane.vect.x, plane.vect.y, plane.vect.z);
	dot2 = dot(p_normal, ray.direction);
	if (fabs(dot2) <= 0.00001)
		return ;
	dot1 = dot(p_normal, subst_tuple(p_point, ray.origin));
	t = dot1 / dot2;
	if (t > 0.000001 && (info->t < 0 || t < info->t))
	{
		info->point = add_tuple(ray.origin, multiply_tuple(ray.direction, t));
		info->color.raw = plane.color;
		info->normal = p_normal;
		info->t = t;
	}
}

