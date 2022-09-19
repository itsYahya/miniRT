#include "raytracer.h"

t_material		ft_material()
{
	t_material	m;

	m.color = ft_color(1, 1, 1);
	m.ambient = 0.1;
	m.diffuse = 0.9;
	m.specular = 0.9;
	m.shininess = 200.0;
	return (m);
}

void	setMatAmbient(t_material *mat, double ambient)
{
	if (ambient < 0.0)
		ambient = 0.0;
	mat->ambient = ambient;
}

void	setMatDiffuse(t_material *mat, double diffuse)
{
	if (diffuse < 0.0)
		diffuse = 0.0;
	mat->diffuse = diffuse;
}

void	setMatSpecular(t_material *mat, double specular)
{
	if (specular < 0.0)
		specular = 0.0;
	mat->specular = specular;
}

void	setMatShininess(t_material *mat, double shininess)
{
	if (shininess < 10.0)
		shininess = 10.0;
	else if (shininess > 200.0)
		shininess = 200.0;
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

void	print_material(t_material m)
{
	print_color(m.color);
	printf("ambient: %f\n", m.ambient);
	printf("diffuse: %f\n", m.diffuse);
	printf("specular: %f\n", m.specular);
	printf("shininess: %f\n", m.shininess);
}
