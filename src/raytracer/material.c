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

void	setMatAmbient(t_material *mat, float ambient)
{
	if (ambient < 0.0f)
		ambient = 0.0f;
	mat->ambient = ambient;
}

void	setMatDiffuse(t_material *mat, float diffuse)
{
	if (diffuse < 0.0f)
		diffuse = 0.0f;
	mat->diffuse = diffuse;
}

void	setMatSpecular(t_material *mat, float specular)
{
	if (specular < 0.0f)
		specular = 0.0f;
	mat->specular = specular;
}

void	setMatShininess(t_material *mat, float shininess)
{
	if (shininess < 10.0f)
		shininess = 10.0f;
	else if (shininess > 200.0f)
		shininess = 200.0f;
	mat->shininess = shininess;
}

bool			material_equal(t_material m1, t_material m2)
{
	return (color_equal(m1.color, m2.color)
		&& m1.ambient == m2.ambient
		&& m1.diffuse == m2.diffuse
		&& m1.specular == m2.specular
		&& m1.shininess == m2.shininess);
}
