#include "raytracer.h"

t_object	ft_plane()
{
	return (new_plane(
		point(0, 0, 0),
		vector(0, 1, 0),
		ft_color(1, 1, 1)
		));
}

t_object	new_plane(t_tuple coords, t_tuple orientation, t_color color)
{
	t_object	object;

	object.material = ft_material();
	object.material.color = color;
	object.type = E_PLANE;
	set_transform(&object, orientation_transform(coords, orientation));
	return (object);
}

t_tuple	local_plane_normal()
{
	return (vector(0, 1, 0));
}

t_xs	local_plane_intersect(t_object plane, t_ray r)
{
	t_xs	xs;
	t_inter	i;

	xs = (t_xs){0, NULL};
	if (equal(r.direction.y, 0.0))
		return (xs);
	i = ft_inter(-r.origin.y / r.direction.y, plane);
	return (ft_inters(1, i));
}
