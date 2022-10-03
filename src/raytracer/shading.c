#include "raytracer.h"

t_tuple	reflect(t_tuple incoming, t_tuple normal)
{
	return subst_tuple(incoming, multiply_tuple(normal, dot(incoming, normal) * 2));
}

t_tuple	ft_lighting(t_material material, t_info *info, t_light light)
{
	t_tuple	effective_color;
	t_tuple	ambient;
	t_tuple diffuse;
	t_tuple	specular;

	effective_color = tuple_product(material.color, light.color);
	t_tuple	lighv = normalize(subst_tuple(light.point, info->point));

	ambient = multiply_tuple(effective_color, material.ambient);
	double lDotN = dot(lighv, info->normal);
	if (info->is_shadowed || lDotN < 0) {
		specular = ft_color(0, 0, 0);
		diffuse = ft_color(0, 0, 0);
	} else {
		diffuse = multiply_tuple(effective_color, material.diffuse * lDotN);
		t_tuple	reflectv = reflect(negate_tuple(lighv), info->normal);
		double rDotE = dot(reflectv, info->eyeV);
		if (rDotE < 0) {
			specular = ft_color(0, 0, 0);
		} else {
			double factor = pow(rDotE, material.shininess);
			specular = multiply_tuple(light.color, material.specular * factor);
		}
	}
	return (add_tuple(ambient, add_tuple(diffuse, specular)));
}

static bool	is_shadowed(t__data *data, t_light light, t_tuple point)
{
	t_tuple	p2l;
	double	p2l_distance;
	t_info	info;

	p2l = subst_tuple(light.point, point);
	p2l_distance = magnitude(p2l);
	p2l = normalize(p2l);
	ft_look_inters(data->objects, ft_ray(point, p2l), &info);
	if (info.t < 0 || info.t >= p2l_distance)
		return (false);
	return (true);
}

// todo check ambient
t_color	ft_shading(t__data *data, t_info *info)
{
	t_list	*lst;
	t_color	color;
	t_light	light;

	color = multiply_tuple(data->ambient.color, data->ambient.ratio);
	if (info->t < 0)
		return (color);
	lst = data->lights;
	while (lst)
	{
		light = *(t_light*)lst->content;
		info->is_shadowed = is_shadowed(data, light, info->point);
		color = add_tuple(color, ft_lighting(info->object.material, info, light));
		lst = lst->next;
	}
	return (color);
}
