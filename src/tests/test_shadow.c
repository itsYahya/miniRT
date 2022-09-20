#include "tests.h"

static void	test_lightning_with_surface_in_shadow()
{
	t_tuple eyev = vector(0, 0, -1);
	t_tuple normalv = vector(0, 0, -1);
	t_light	light = point_light(point(0, 0, -10), ft_color(1, 1, 1), 1);
	bool in_shadow = true;

	t_color result = ft_lighting(ft_material(), light, point(0, 0, 0), eyev, normalv, in_shadow);
	assert(color_equal(result, ft_color(0.1, 0.1, 0.1)));
}

static void test_no_shadow_when_nothing_is_collinear_with_point_and_light()
{
	t_scene s = default_scene();
	t_tuple p = point(0, 10, 0);
	t_light	l = *get_light_at(s.lights, 0);

	bool result = is_shadowed(s, l, p);
	assert(result == false);
}

static void	test_shadow_when_an_object_between_point_and_light()
{
	t_scene s = default_scene();
	t_tuple p = point(10, -10, 10);
	t_light	l = *get_light_at(s.lights, 0);

	bool result = is_shadowed(s, l, p);
	assert(result == true);
}

static void	test_no_shadow_when_an_object_behind_light()
{
	t_scene s = default_scene();
	t_tuple p = point(-20, 20, -20);
	t_light	l = *get_light_at(s.lights, 0);

	bool result = is_shadowed(s, l, p);
	assert(result == false);
}

static void test_no_shadow_when_an_object_behind_point()
{
	t_scene s = default_scene();
	t_tuple p = point(-2, 2, -2);
	t_light	l = *get_light_at(s.lights, 0);

	bool result = is_shadowed(s, l, p);
	assert(result == false);
}

static void test_shade_hit_given_intersection_in_shadow()
{
	t_scene s = default_scene();
	get_light_at(s.lights, 0)->position = point(0, 0, -10);
	get_light_at(s.lights, 0)->color = ft_color(1, 1, 1);
	t_object s1 = ft_sphere();
	add_object(&s, s1);
	t_object s2 = ft_sphere();
	set_transform(&s2, translate(0, 0, 10));
	add_object(&s, s2);
	t_ray r = ft_ray(point(0, 0, 5), vector(0, 0, 1));
	t_inter i = ft_inter(4, s2);
	t_computations comps = prepare_computations(i, r);
	t_color c = shade_hit(s, comps);
	assert(color_equal(c, ft_color(0.1, 0.1, 0.1)));
}

static void	test_hit_should_offset_point()
{
	t_ray r = ft_ray(point(0, 0, -5), vector(0, 0, 1));
	t_object s = ft_sphere();
	set_transform(&s, translate(0, 0, 1));
	t_inter i = ft_inter(5, s);
	t_computations comps = prepare_computations(i, r);
	assert(comps.adjusted_point.z < -EPSILON / 2.0);
	assert(comps.point.z > comps.adjusted_point.z);
}

void	test_shadow()
{
	printf("=> shadow test: ");
	test_lightning_with_surface_in_shadow();
	test_no_shadow_when_nothing_is_collinear_with_point_and_light();
	test_shadow_when_an_object_between_point_and_light();
	test_no_shadow_when_an_object_behind_light();
	test_no_shadow_when_an_object_behind_point();
	printf("OK\n");
	printf("=> shad_hit() test: ");
	test_shade_hit_given_intersection_in_shadow();
	test_hit_should_offset_point();
	printf("OK\n");
}
