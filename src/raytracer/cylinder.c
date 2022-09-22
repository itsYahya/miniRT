#include "raytracer.h"

t_object	ft_cylinder()
{
	t_object	obj;

	obj.type = E_CYLINDER;
	set_transform(&obj, IDENTITY_MATRIX);
	obj.material = ft_material();
	obj.cy.min_y = -MAXFLOAT;
	obj.cy.max_y = MAXFLOAT;
	obj.cy.radius = 1.0;
	return (obj);
}

t_object	new_cylinder(t_tuple coords, t_tuple orientation, t_fpair radius_height, t_color color)
{
	t_object	object;
	double		height;
	t_matrix	transform;

	height = radius_height._1;
	object.material = ft_material();
	object.material.color = color;
	object.type = E_CYLINDER,
	object.cy.min_y = -height / 2.0;
	object.cy.max_y = height / 2.0;
	object.cy.radius = radius_height._0;
	transform = orientation_transform(coords, orientation);
	set_transform(&object, transform);
	return (object);
}

t_tuple	local_cylinder_normal(t_tuple p)
{
	return (vector(p.x, 0, p.z));
}

# define VALID_Y(y) (y > obj.cy.min_y && y < obj.cy.max_y)

static t_xs	validate_intersections(t_ray r, t_fpair t, t_object obj)
{
	double	y0;
	double	y1;

	if (t._0 > t._1)
		swap(&t._0, &t._1);
	y0 = ft_position(r, t._0).y;
	y1 = ft_position(r, t._1).y;
	if (VALID_Y(y0) && VALID_Y(y1))
		return (ft_inters(2, ft_inter(t._0, obj), ft_inter(t._1, obj)));
	else if (VALID_Y(y0))
		return (ft_inters(1, ft_inter(t._0, obj)));
	else if (VALID_Y(y1))
		return (ft_inters(1, ft_inter(t._1, obj)));
	return ((t_xs){0, NULL});
}

t_xs	local_cylinder_intersect(t_object cy, t_ray r)
{
	t_params	params;
	t_fpair		t;

	params.a = pow(r.direction.x, 2) + pow(r.direction.z, 2);
	if (equal(params.a, 0.0))
		return ((t_xs){0, NULL});
	params.b = 2 * (r.origin.x * r.direction.x + r.origin.z * r.direction.z);
	params.c = pow(r.origin.x, 2) + pow(r.origin.z, 2) - pow(cy.cy.radius, 2);
	params.desc = params.b * params.b - 4 * params.a * params.c;
	if (params.desc < 0)
		return ((t_xs){0, NULL});
	t._0 = (-params.b - sqrt(params.desc)) / (2 * params.a);
	t._1 = (-params.b + sqrt(params.desc)) / (2 * params.a);
	return (validate_intersections(r, t, cy));
}
