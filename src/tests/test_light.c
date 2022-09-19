#include "tests.h"

// normal test
static void	normal_at_simple_sphere()
{
	t_tuple		normal;
	t_object s = ft_sphere();

	normal = normal_at(s, point(1, 0, 0));
	assert(is_equal(normal, vector(1, 0, 0)));
	normal = normal_at(s, point(0, 1, 0));
	assert(is_equal(normal, vector(0, 1, 0)));
	normal = normal_at(s, point(0, 0, 1));
	assert(is_equal(normal, vector(0, 0, 1)));
	normal = normal_at(s, point(sqrt(3) / 3, sqrt(3) / 3, sqrt(3) / 3));
	assert(is_equal(normal, vector(sqrt(3) / 3, sqrt(3) / 3, sqrt(3) / 3)));
}

static void	normal_at_transformed_sphere()
{
	t_tuple		normal;
	t_object s = ft_sphere();

	set_transform(&s, translate(0, 1, 0));
	normal = normal_at(s, point(0, 1.70711, -0.70711));
	assert(is_equal(normal, vector(0, 0.70711, -0.70711)));

	set_transform(&s, transforms(2, scale(1, 0.5, 1), rotate_z(M_PI / 5.0)));
	normal = normal_at(s, point(0, sqrt(2)/2, -sqrt(2)/2));
	assert(is_equal(normal, vector(0, 0.97014, -0.24254)));
}

// refection test
static void	reflectv_45()
{
	t_tuple	v = vector(1, -1, 0);
	t_tuple	n = vector(0, 1, 0);
	t_tuple	r = reflect(v, n);
	assert(is_equal(r, vector(1, 1, 0)));
}

static void	reflectv_slanted_surface()
{
	t_tuple	v = vector(0, -1, 0);
	t_tuple	n = vector(sqrt(2) / 2, sqrt(2) / 2, 0);
	t_tuple	r = reflect(v, n);
	assert(is_equal(r, vector(1, 0, 0)));
}

// light test
static void light_has_position_intensity()
{
	t_light	light = point_light(point(0, 0, 0), ft_color(1, 1, 1), 1);

	assert(is_equal(light.position, point(0, 0, 0)));
	assert(is_equal(light.color, ft_color(1, 1, 1)));
}

static void	material_default()
{
	t_material	m = ft_material();

	assert(is_equal(m.color, ft_color(1, 1, 1)));
	assert(m.ambient == 0.1);
	assert(m.diffuse == 0.9);
	assert(m.specular == 0.9);
	assert(m.shininess == 200.0);
}

static void	sphere_has_default_material()
{
	t_object	s = ft_sphere();

	assert(material_equal(s.material, ft_material()));
}

static void	assigne_material_to_sphere()
{
	t_object	s = ft_sphere();
	t_material	m = ft_material();

	setMatAmbient(&m, 1);
	s.material = m;
	assert(material_equal(s.material, m));
}

static void	lighting_eye_between_light_and_surface()
{
	t_material	m = ft_material();
	t_tuple		position = point(0, 0, 0);

	t_tuple		eyev = vector(0, 0, -1);
	t_tuple		normalv = vector(0, 0, -1);
	t_light		light = point_light(point(0, 0, -10), ft_color(1, 1, 1), 1);
	t_color		result = ft_lighting(m, light, position, eyev, normalv, false);
	assert(is_equal(result, ft_color(1.9, 1.9, 1.9)));
}

static void	lighting_eye_between_light_and_surface_eye_offset_45()
{
	t_material	m = ft_material();
	t_tuple		position = point(0, 0, 0);

	t_tuple		eyev = vector(0, sqrt(2) / 2, -sqrt(2) / 2);
	t_tuple		normalv = vector(0, 0, -1);
	t_light		light = point_light(point(0, 0, -10), ft_color(1, 1, 1), 1);
	t_color		result = ft_lighting(m, light, position, eyev, normalv, false);
	assert(is_equal(result, ft_color(1.0, 1.0, 1.0)));
}

static void	lightning_eye_opposite_surface_light_offset_45()
{
	t_material	m = ft_material();
	t_tuple		position = point(0, 0, 0);

	t_tuple		eyev = vector(0, 0, -1);
	t_tuple		normalv = vector(0, 0, -1);
	t_light		light = point_light(point(0, 10, -10), ft_color(1, 1, 1), 1);
	t_color		result = ft_lighting(m, light, position, eyev, normalv, false);
	assert(is_equal(result, ft_color(0.7364, 0.7364, 0.7364)));
}

static void	lightning_eye_in_path_of_reflection_vector()
{
	t_material	m = ft_material();
	t_tuple		position = point(0, 0, 0);

	t_tuple		eyev = vector(0, -sqrt(2) / 2, -sqrt(2) / 2);
	t_tuple		normalv = vector(0, 0, -1);
	t_light		light = point_light(point(0, 10, -10), ft_color(1, 1, 1), 1);
	t_color		result = ft_lighting(m, light, position, eyev, normalv, false);
	assert(is_equal(result, ft_color(1.6364, 1.6364, 1.6364)));
}

static void	lightning_with_the_light_behind_the_surface()
{
	t_material	m = ft_material();
	t_tuple		position = point(0, 0, 0);

	t_tuple		eyev = vector(0, 0, -1);
	t_tuple		normalv = vector(0, 0, -1);
	t_light		light = point_light(point(0, 0, 10), ft_color(1, 1, 1), 1);
	t_color		result = ft_lighting(m, light, position, eyev, normalv, false);
	assert(is_equal(result, ft_color(0.1, 0.1, 0.1)));
}

void	test_light()
{
	printf("=> reflect test: ");
	reflectv_45();
	reflectv_slanted_surface();
	printf("OK\n");

	printf("=> normal_at test: ");
	normal_at_simple_sphere();
	normal_at_transformed_sphere();
	printf("OK\n");

	printf("=> light test: ");
	light_has_position_intensity();
	material_default();
	sphere_has_default_material();
	assigne_material_to_sphere();
	lighting_eye_between_light_and_surface();
	lighting_eye_between_light_and_surface_eye_offset_45();
	lightning_eye_opposite_surface_light_offset_45();
	lightning_eye_in_path_of_reflection_vector();
	lightning_with_the_light_behind_the_surface();
	printf("OK\n");
}
