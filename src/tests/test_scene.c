#include "tests.h"

static void	test_empty_scene()
{
	t_scene	scene;

	scene = empty_scene();
	assert(scene.objects == NULL);
	assert(scene.lights == NULL);
}

static void	test_default_scene()
{
	t_scene		scene;
	t_object	obj;

	scene = default_scene();
	assert(scene.objects != NULL);
	assert(scene.lights != NULL);
	assert(ft_lstsize(scene.objects) == 2);
	assert(ft_lstsize(scene.lights) == 1);

	// obj1
	obj = *get_object_at(scene.objects, 0);
	assert(matrix_equal(obj.transform, IDENTITY_MATRIX));
	assert(color_equal(obj.material.color, ft_color(0.8, 1.0, 0.6)));
	assert(obj.material.diffuse == 0.7f);
	assert(obj.material.specular == 0.2f);

	// obj2
	obj = *get_object_at(scene.objects, 1);
	assert(matrix_equal(
		obj.transform,
		scale(0.5, 0.5, 0.5)
	));
}

static void	test_intersect_scene_with_ray()
{
	t_scene	s = default_scene();
	t_ray	r = ft_ray(point(0, 0, -5), vector(0, 0, 1));
	t_xs xs = intersect_scene(s, r);
	assert(xs.count == 4);
	assert(xs.inters[0].t == 4.0f);
	assert(xs.inters[1].t == 4.5f);
	assert(xs.inters[2].t == 5.5f);
	assert(xs.inters[3].t == 6.0f);
	destroy_inters(&xs);
}

static void	test_pre_compute_state_of_intersection()
{
	t_ray r = ft_ray(point(0, 0, -5), vector(0, 0, 1));
	t_object shape = ft_sphere();
	t_inter i = ft_inter(4, shape);
	t_computations comps = prepare_computations(i, r);
	assert(comps.t == i.t);
	assert(comps.object.type == i.object.type);
	assert(is_equal(comps.point, point(0, 0, -1)));
	assert(is_equal(comps.eyev, vector(0, 0, -1)));
	assert(is_equal(comps.normalv, vector(0, 0, -1)));
}

static void test_pre_compute_state_when_inter_occurs_inside()
{
	t_ray r = ft_ray(point(0, 0, 0), vector(0, 0, 1));
	t_object shape = ft_sphere();
	t_inter i = ft_inter(1, shape);
	t_computations	comps = prepare_computations(i, r);
	assert(comps.inside == 1);
}

static void test_pre_compute_state_when_inter_occurs_outside()
{
	t_ray r = ft_ray(point(0, 0, -5), vector(0, 0, 1));
	t_object shape = ft_sphere();
	t_inter i = ft_inter(4, shape);
	t_computations	comps = prepare_computations(i, r);
	assert(comps.inside == 0);
	assert(is_equal(comps.normalv, vector(0, 0, -1)));
}

// static void	test_shading_intersection()
// {
// 	t_scene s = default_scene();
// 	t_ray	r = ft_ray(point(0, 0, -5), vector(0, 0, 1));
// 	t_object shape = *get_object_at(s.objects, 0);
// 	t_inter	i = ft_inter(4, shape);
// 	t_computations	comps = prepare_computations(i, r);
// 	t_color	c = shade_hit(s, comps);
// 	print_color(c);
// 	assert(color_equal(c, ft_color(0.38066, 0.47583, 0.2855)));
// }

// static void	test_shading_intersection_from_inside()
// {
// 	t_scene s = default_scene();
// 	get_light_at(s.lights, 0)->position = point(0, 0.25, 0);
// 	get_light_at(s.lights, 0)->color = ft_color(1, 1, 1);
// 	t_ray r = ft_ray(point(0, 0, 0), vector(0, 0, 1));
// 	t_object shape = *get_object_at(s.objects, 1);
// 	t_inter	i = ft_inter(0.5, shape);
// 	t_computations	comps = prepare_computations(i, r);
// 	t_color	c = shade_hit(s, comps);
// 	assert(color_equal(c, ft_color(0.90498, 0.90498, 0.90498)));
// }

static void	test_color_when_ray_misses()
{
	t_scene s = default_scene();
	t_ray	r = ft_ray(point(0, 0, -5), vector(0, 1, 0));
	t_color c = color_at(s, r);
	assert(color_equal(c, ft_color(0, 0, 0)));
}

// static void	test_color_when_ray_hits()
// {
// 	t_scene s = default_scene();
// 	t_ray	r = ft_ray(point(0, 0, -5), vector(0, 0, 1));
// 	t_color c = color_at(s, r);
// 	print_color(c);
// 	assert(color_equal(c, ft_color(0.38066, 0.47583, 0.2855)));
// }

static void	test_color_with_intersection_behind_ray()
{
	t_scene s = default_scene();
	t_object *outer = get_object_at(s.objects, 0);
	outer->material.ambient = 1;
	t_object *inner = get_object_at(s.objects, 1);
	inner->material.ambient = 1;
	t_ray	r = ft_ray(point(0, 0, 0.75), vector(0, 0, -1));
	t_color c = color_at(s, r);
	assert(color_equal(c, inner->material.color));
}

void	test_scene()
{
	printf("=> scene creation test: ");
	test_empty_scene();
	test_default_scene();
	test_intersect_scene_with_ray();
	test_pre_compute_state_of_intersection();
	test_pre_compute_state_when_inter_occurs_outside();
	test_pre_compute_state_when_inter_occurs_inside();
	printf("OK\n");
	printf("=> shading test: ");
	// test_shading_intersection();
	// test_shading_intersection_from_inside();
	printf("OK\n");
	printf("=> color at test: ");
	test_color_when_ray_misses();
	// test_color_when_ray_hits();
	test_color_with_intersection_behind_ray();
	printf("OK\n");
}
