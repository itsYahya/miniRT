#include "raytracer.h"

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

t_tuple	ft_lighting(t_material material, t_light light, t_tuple position, t_tuple eyev, t_tuple normalv)
{
	t_tuple	effective_color;
	t_tuple	ambient;
	t_tuple diffuse;
	t_tuple	specular;

	effective_color = tuple_product(material.color, light.intensity);
	t_tuple	lighv = normalize(subst_tuple(light.position, position));

	// ambient
	ambient = multiply_tuple(effective_color, material.ambient);

	// diffuse + specular
	float lDotN = dot(lighv, normalv);
	if (lDotN < 0) {
		specular = ft_color(0, 0, 0);
		diffuse = ft_color(0, 0, 0);
	} else {
		// diffuse
		diffuse = multiply_tuple(effective_color, material.diffuse * lDotN);

		t_tuple	reflectv = reflect(negate_tuple(lighv), normalv);
		float rDotE = dot(reflectv, eyev);
		if (rDotE < 0) {
			specular = ft_color(0, 0, 0);
		} else {
			float factor = pow(rDotE, material.shininess);
			specular = multiply_tuple(light.intensity, material.specular * factor);
		}
	}
	return (add_tuple(ambient, add_tuple(diffuse, specular)));
}
