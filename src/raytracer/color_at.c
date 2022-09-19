#include "raytracer.h"

void	print_comps(t_computations comps)
{
	printf("t: %f\n", comps.t);
	printf("point: "); print_point(comps.point);
	printf("eyev: "); print_vector(comps.eyev);
	printf("normalv: "); print_vector(comps.normalv);
	printf("inside: %d\n", comps.inside);
}

t_computations			prepare_computations(t_inter intersection, t_ray r)
{
	t_computations comps;

	comps.t = intersection.t;
	comps.object = intersection.object;
	comps.point = ft_position(r, comps.t);
	comps.eyev = negate_tuple(r.direction);
	comps.normalv = normal_at(comps.object, comps.point);
	comps.inside = false;
	if (dot(comps.normalv, comps.eyev) < 0)
	{
		comps.inside = true;
		comps.normalv = negate_tuple(comps.normalv);
	}
	return (comps);
}

t_color	shade_hit(t_scene scene, t_computations comps)
{
	t_list	*lst;
	t_color	color;

	color = ft_color(0, 0, 0);
	if (comps.t < 0)
		return (color);
	lst = scene.lights;
	while (lst)
	{
		color = add_tuple(color, ft_lighting(
			comps.object.material,
			*get_light(lst),
			comps.point,
			comps.eyev,
			comps.normalv
		));
		lst = lst->next;
	}
	return (color);
}

t_color color_at(t_scene w, t_ray r)
{
	t_xs			xs;
	t_inter	intersection;
	t_computations			comps;

	xs = intersect_scene(w, r);
	intersection = ft_hit(xs);
	if (intersection.t < 0)
		return ft_color(0, 0, 0);
	comps = prepare_computations(intersection, r);
	return shade_hit(w, comps);
}
