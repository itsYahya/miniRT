#include "raytracer.h"

void	print_comps(t_comps comps)
{
	printf("t: %f\n", comps.t);
	printf("point: "); print_point(comps.point);
	printf("eyev: "); print_vector(comps.eyev);
	printf("normalv: "); print_vector(comps.normalv);
	printf("inside: %d\n", comps.inside);
}

t_comps			hitpoint_info(t_intersection intersection, t_ray r)
{
	t_comps comps;

	comps.t = intersection.t;
	comps.object = intersection.object;
	comps.point = ft_position(r, comps.t);
	comps.eyev = negate_tuple(r.direction);
	comps.normalv = normal_at(comps.object, comps.point);
	comps.inside = false;
	if (dot(comps.normalv, comps.eyev) < 0)
	{
		comps.inside = true;
		comps.eyev = negate_tuple(comps.eyev);
	}
	return (comps);
}

t_color	shade_hit(t_world w, t_comps comps)
{
	return ft_lighting(comps.object.material, w.light, comps.point, comps.eyev, comps.normalv);
}

t_color color_at(t_world w, t_ray r)
{
	t_xs			xs;
	t_intersection	intersection;
	t_comps			comps;

	xs = intersect_world(w, r);
	intersection = ft_hit(xs);
	if (intersection.t < 0)
		return ft_color(0, 0, 0);
	comps = hitpoint_info(intersection, r);
	return shade_hit(w, comps);
}
