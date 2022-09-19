#include "tests.h"

static void	test_creating_ray()
{
	t_tuple	origin = point(1, 2, 3);
	t_tuple	direction = vector(4, 5, 6);

	t_ray	ray = ft_ray(origin, direction);
	assert(is_equal(ray.origin, origin));
	assert(is_equal(ray.direction, direction));
}

static void	compute_point_form_distance()
{
	t_ray r = ft_ray(point(2, 3, 4), vector(1, 0, 0));
	assert(is_equal(ft_position(r, 0), point(2, 3, 4)));
	assert(is_equal(ft_position(r, 1), point(3, 3, 4)));
	assert(is_equal(ft_position(r, -1), point(1, 3, 4)));
	assert(is_equal(ft_position(r, 2.5), point(4.5, 3, 4)));
}

static void intersect_ray_with_sphere_at_two_points()
{
	t_ray	r = ft_ray(point(0, 0, -5), vector(0, 0, 1));
	t_object s = ft_sphere();
	t_xs	xs = intersect(s, r);
	assert(xs.count == 2);
	assert(xs.inters[0].t == 4.0);
	assert(xs.inters[1].t == 6.0);
	destroy_inters(&xs);
}

static void	intersect_sphere_at_tangent()
{
	t_ray	r = ft_ray(point(0, 1, -5), vector(0, 0, 1));
	t_object s = ft_sphere();
	t_xs	xs = intersect(s, r);
	assert(xs.count == 2);
	assert(xs.inters[0].t == 5.0);
	assert(xs.inters[1].t == 5.0);
	destroy_inters(&xs);
}

static void	ray_miss_sphere()
{
	t_ray	r = ft_ray(point(0, 2, -5), vector(0, 0, 1));
	t_object s = ft_sphere();
	t_xs	xs = intersect(s, r);
	assert(xs.count == 0);
	assert(xs.inters == NULL);
	destroy_inters(&xs);
}

static void	ray_inside_sphere()
{
	t_object	s = ft_sphere();
	t_ray		r = ft_ray(point(0, 0, 0), vector(0, 0, 1));

	t_xs xs = intersect(s, r);
	assert(xs.count == 2);
	assert(xs.inters[0].t == -1.0);
	assert(xs.inters[1].t == 1.0);
}

static void	sphere_is_behind_ray()
{
	t_object	s = ft_sphere();
	t_ray		r = ft_ray(point(0, 0, 5), vector(0, 0, 1));

	t_xs xs = intersect(s, r);
	assert(xs.count == 2);
	assert(xs.inters[0].t == -6.0);
	assert(xs.inters[1].t == -4.0);
	destroy_inters(&xs);
}

static void intersection_encapsulate_t_object()
{
	t_ray	r = ft_ray(point(0, 0, -5), vector(0, 0, 1));
	t_object s = ft_sphere();
	t_xs	xs = intersect(s, r);
	assert(xs.inters[0].object.type == E_SPHERE);
	assert(xs.inters[1].object.type == E_SPHERE);
	destroy_inters(&xs);
}

static void hit_when_all_intersections_have_positive_t()
{
	t_object s = ft_sphere();
	t_inter i1 = ft_inter(1, s);
	t_inter	i2 = ft_inter(2, s);
	t_xs xs = ft_inters(2, i1, i2);
	t_inter i = ft_hit(xs);
	assert(i.t == i1.t);
	assert(i.object.type == i1.object.type);
}

static void hit_when_some_intersections_have_negative_t()
{
	t_object s = ft_sphere();
	t_inter i1 = ft_inter(-1, s);
	t_inter	i2 = ft_inter(1, s);
	t_xs xs = ft_inters(2, i1, i2);
	t_inter i = ft_hit(xs);
	assert(i.t == i2.t);
	assert(i.object.type == i2.object.type);
}

static void hit_when_all_intersections_have_negative_t()
{
	t_object s = ft_sphere();
	t_inter i1 = ft_inter(-2, s);
	t_inter	i2 = ft_inter(-1, s);
	t_xs xs = ft_inters(2, i1, i2);
	t_inter i = ft_hit(xs);
	assert(i.t == -1);
	assert(i.object.type == E_INVALID);
}

static void	hit_is_always_lowest_nonnegative_intersection()
{
	t_object s = ft_sphere();
	t_inter i1 = ft_inter(5, s);
	t_inter	i2 = ft_inter(7, s);
	t_inter	i3 = ft_inter(-3, s);
	t_inter	i4 = ft_inter(2, s);
	t_xs xs = ft_inters(4, i1, i2, i3, i4);
	t_inter i = ft_hit(xs);
	assert(i.t == i4.t);
	assert(i.object.type == i4.object.type);
}

static void	translate_ray()
{
	t_ray	r = ft_ray(point(1, 2, 3), vector(0, 1, 0));
	t_matrix m = translate(3, 4, 5);
	t_ray	r2 = ray_transform(r, m);
	assert(is_equal(r2.origin, point(4, 6, 8)));
	assert(is_equal(r2.direction, vector(0, 1, 0)));
}

static void scaling_ray()
{
	t_ray	r = ft_ray(point(1, 2, 3), vector(0, 1, 0));
	t_matrix m = scale(2, 3, 4);
	t_ray	r2 = ray_transform(r, m);
	assert(is_equal(r2.origin, point(2, 6, 12)));
	assert(is_equal(r2.direction, vector(0, 3, 0)));
}

static void	sphere_default_transformation()
{
	t_object s = ft_sphere();
	assert(matrix_equal(s.transform, IDENTITY_MATRIX));
}

static void	change_sphere_transformation()
{
	t_object s = ft_sphere();
	t_matrix m = translate(2, 3, 4);
	set_transform(&s, m);
	assert(matrix_equal(s.transform, m));
}

static void	intersect_scaled_sphere_with_ray()
{
	t_ray	r = ft_ray(point(0, 0, -5), vector(0, 0, 1));
	t_object s = ft_sphere();
	set_transform(&s, scale(2, 2, 2));
	t_xs	xs = intersect(s, r);
	assert(xs.count == 2);
	assert(xs.inters[0].t == 3);
	assert(xs.inters[1].t == 7);
	destroy_inters(&xs);
}

void	test_raysphere()
{
	printf("=> ray sphere intersection test: ");
	test_creating_ray();
	compute_point_form_distance();
	intersect_ray_with_sphere_at_two_points();
	intersect_sphere_at_tangent();
	ray_miss_sphere();
	ray_inside_sphere();
	sphere_is_behind_ray();
	intersection_encapsulate_t_object();
	hit_when_all_intersections_have_positive_t();
	hit_when_some_intersections_have_negative_t();
	hit_when_all_intersections_have_negative_t();
	hit_is_always_lowest_nonnegative_intersection();
	printf("OK\n");
	printf("=> ray sphere transform test: ");
	translate_ray();
	scaling_ray();
	sphere_default_transformation();
	change_sphere_transformation();
	intersect_scaled_sphere_with_ray();
	printf("OK\n");
}
