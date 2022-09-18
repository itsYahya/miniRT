#include "raytracer.h"
#include <stdio.h>

t_tuple	reflect(t_tuple incoming, t_tuple normal)
{
	return subst_tuple(incoming, multiply_tuple(normal, dot(incoming, normal) * 2));
}

t_light	point_light(t_tuple position, t_color intensity)
{
	return (t_light){position, intensity};
}

t_tuple	ft_correct_color(t_tuple color)
{
	if (color.r > 1)
		color.r = 1;
	if (color.g > 1)
		color.g = 1;
	if (color.b > 1)
		color.b = 1;
	color.a = 0;
	return (color);
}

t_tuple	ft_lighting(t_material material, t_light light, t_tuple position,
			t_tuple eyev, t_tuple normalv)
{
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
	t_tuple result = (add_tuple(ambient, add_tuple(diffuse, specular)));
	return (ft_correct_color(result));
}
