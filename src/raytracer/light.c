#include "raytracer.h"
#include <stdio.h>

t_tuple			normal_at(t_object object, t_tuple p)
{
	t_tuple normal;

	p = matrix_tuple_multiply(object.transform_matrix, p);
	normal = subst_tuple(p, point(0, 0, 0));
	normal = matrix_tuple_multiply(
					ft_transpose(inverse(object.transform_matrix)),
					normal
					);
	normal.w = 0;
	return (normalize(normal));
}

t_tuple			reflect(t_tuple v, t_tuple normal)
{
	return subst_tuple(v, multiply_tuple(normal, dot(v, normal) * 2));
}

t_light	point_light(t_tuple position, t_color intensity)
{
	return (t_light){position, intensity};
}

t_tuple	ft_lighting(t_material material, t_light light, t_tuple position,
			t_tuple eyev, t_tuple normalv)
{
	// TODO: fix
	// t_world w = default_world();
	// t_ray	r = ft_ray(point(0, 0, -5), vector(0, 0, 1));
	// t_object sp = *(t_object *)w.objects->content;
	// t_intersection inter = ft_intersection(4, sp);
	// t_comps comps = hitpoint_info(inter, r);
	// t_color c = shade_hit(w, comps);
	// print_color(c);
	// c = color(0.38066, 0.47583, 0.2855)

	t_tuple	diffuse = ft_color(0, 0, 0);
	t_tuple specular = ft_color(0, 0, 0);
	t_tuple lightv = normalize(subst_tuple(light.position, position));
	t_color	effictive_color = ft_hadamard_product(material.color, light.intensity);
	t_tuple	ambient = multiply_tuple(effictive_color, material.ambient);
	float light_dot_normal = dot(lightv, normalv);

	if (light_dot_normal < 0)
		return (add_tuple(ambient, add_tuple(diffuse, specular)));
	diffuse = multiply_tuple(effictive_color, material.diffuse * light_dot_normal);
	t_tuple reflectv = reflect(multiply_tuple(lightv, -1), normalv);
	float reflect_dot_eye = dot(reflectv, eyev);
	if (reflect_dot_eye <= 0)
		specular = ft_color(0, 0, 0);
	else
	{
		float factor = pow(reflect_dot_eye, material.shininess);
		specular = multiply_tuple(light.intensity, material.specular * factor);
	}
	return (add_tuple(ambient, add_tuple(diffuse, specular)));
}
