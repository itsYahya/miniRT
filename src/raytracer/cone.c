#include "raytracer.h"

t_object	infinite_cone()
{
	t_object	obj;

	obj.type = E_CONE;
	set_transform(&obj, IDENTITY_MATRIX);
	obj.material = ft_material();
	obj.min_y = -MAXFLOAT;
	obj.max_y = MAXFLOAT;
	return (obj);
}

t_object	new_cone(t_tuple coords, t_tuple orientation, t_fpair radius_height, t_color color)
{
	t_object	object;
	double		radius;
	double		height;
	t_matrix	transform;

	radius = radius_height._0;
	height = radius_height._1;
	object.material = ft_material();
	object.material.color = color;
	object.type = E_CONE;
	object.min_y = -1;
	object.max_y = 1;
	transform = transforms(2,
		orientation_transform(coords, orientation),
		scale(radius, height / 2, radius)
	);
	set_transform(&object, transform);
	return (object);
}

t_tuple	local_cone_normal(t_tuple p)
{
	double	y;

	y = sqrt(pow(p.x, 2) + pow(p.z, 2));
	if (p.y > 0)
		y *= -1;
	return (vector(p.x, y, p.z));
}

t_xs	local_cone_intersect(t_object obj, t_ray r)
{
	t_xs		xs;
	t_params	params;
	t_fpair		t;

	xs = (t_xs){0, NULL};

	params.a = pow(r.dx, 2) - pow(r.dy, 2) + pow(r.dz, 2);
	params.b = 2 * (r.ox * r.dx - r.oy * r.dy + r.oz * r.dz);
	params.c = pow(r.ox, 2) - pow(r.oy, 2) + pow(r.oz, 2);

	if (params.a == 0.0 && params.b == 0.0)
		return (xs);
	if (params.a == 0.0)
	{
		t._0 = -params.c / params.b;
		return ft_inters(1, ft_inter(t._0, obj));
	}
	params.desc = pow(params.b, 2) - 4 * params.a * params.c;
	if (params.desc < 0)
		return (xs);
	t._0 = (-params.b - sqrt(params.desc)) / (2 * params.a);
	t._1 = (-params.b + sqrt(params.desc)) / (2 * params.a);
	return cy_validate_local_inters(r, t, obj);
}
