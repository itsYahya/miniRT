#include "raytracer.h"

bool	is_shadowed(t_scene s, t_light light, t_tuple point)
{
	t_tuple	p2l;
	float	p2l_distance;
	t_xs 	xs;
	t_inter	i;

	p2l = subst_tuple(light.position, point);
	p2l_distance = magnitude(p2l);
	p2l = normalize(p2l);
	xs = intersect_scene(s, ft_ray(point, p2l));
	i = ft_hit(xs);
	destroy_inters(&xs);
	if (i.t < 0 || i.t >= p2l_distance)
		return (false);
	return (true);
}
