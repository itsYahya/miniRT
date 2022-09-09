#include "raytracer.h"

t_material		ft_material()
{
	t_material	m;

	m.color = ft_color(1, 1, 1);
	m.ambient = 0.1f;
	m.diffuse = 0.9f;
	m.specular = 0.9f;
	m.shininess = 200.0f;
	return (m);
}

bool			material_equal(t_material m1, t_material m2)
{
	return (color_equal(m1.color, m2.color)
		&& m1.ambient == m2.ambient
		&& m1.diffuse == m2.diffuse
		&& m1.specular == m2.specular
		&& m1.shininess == m2.shininess);
}
