/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:02:12 by mzarhou           #+#    #+#             */
/*   Updated: 2022/10/03 16:46:11 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

typedef struct s_lighting_info	t_lighting_info;
struct s_lighting_info
{
	t_tuple	ambient;
	t_tuple	diffuse;
	t_tuple	specular;
	t_tuple	lighv;
	t_tuple	reflectv;
};

t_tuple	reflect(t_tuple incoming, t_tuple normal)
{
	return (subst_tuple(
			incoming,
			multiply_tuple(normal, dot(incoming, normal) * 2)));
}

t_tuple	ft_lighting(t_material material, t_info *info, t_light light)
{
	t_tuple			effective_color;
	double			l_dot_n;
	double			r_dot_e;
	double			factor;
	t_lighting_info	vects;

	effective_color = tuple_product(material.color, light.color);
	effective_color = multiply_tuple(effective_color, light.bratio);
	vects.lighv = normalize(subst_tuple(light.point, info->point));
	vects.ambient = multiply_tuple(effective_color, material.ambient);
	l_dot_n = ft_max(dot(vects.lighv, info->normal), 0);
	vects.diffuse = multiply_tuple(effective_color, material.diffuse * l_dot_n);
	vects.reflectv = reflect(negate_tuple(vects.lighv), info->normal);
	r_dot_e = ft_max(dot(vects.reflectv, info->eye_v), 0);
	factor = pow(r_dot_e, material.shininess);
	vects.specular = multiply_tuple(light.color, material.specular * factor);
	if (info->is_shadowed)
	{
		vects.specular = ft_color(0, 0, 0);
		vects.diffuse = ft_color(0, 0, 0);
	}
	return (add_tuple(vects.ambient, add_tuple(vects.diffuse, vects.specular)));
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
		light = *(t_light *)lst->content;
		info->is_shadowed = is_shadowed(data, light, info->point);
		color = add_tuple(
				color,
				ft_lighting(info->object.material, info, light)
				);
		lst = lst->next;
	}
	return (color);
}
