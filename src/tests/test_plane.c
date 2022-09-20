#include "tests.h"

static void	normal_of_plane_is_constrant()
{
	t_object	plane = ft_plane();
	assert(plane.type == E_PLANE);
	t_tuple	n1 = local_plane_normal(point(0, 0, 0));
	t_tuple	n2 = local_plane_normal(point(10, 0, -10));
	t_tuple	n3 = local_plane_normal(point(-5, 0, 150));
	assert(is_equal(n1, vector(0, 1, 0)));
	assert(is_equal(n2, vector(0, 1, 0)));
	assert(is_equal(n3, vector(0, 1, 0)));
}

static void	intersect_with_ray_parallel_to_plane()
{
	t_object p = ft_plane();
	t_ray	r = ft_ray(point(0, 10, 0), vector(0, 0, 1));

	t_xs xs = local_plane_intersect(p, r);
	assert(xs.count == 0);
	assert(xs.inters == NULL);
}

static void	intersect_with_coplanar_ray()
{
	t_object p = ft_plane();
	t_ray	r = ft_ray(point(0, 0, 0), vector(0, 0, 1));

	t_xs xs = local_plane_intersect(p, r);
	assert(xs.count == 0);
	assert(xs.inters == NULL);
}

static void	intersect_with_ray_from_above()
{
	t_object p = ft_plane();
	t_ray	r = ft_ray(point(0, 1, 0), vector(0, -1, 0));

	t_xs xs = local_plane_intersect(p, r);
	assert(xs.count == 1);
	assert(xs.inters[0].t == 1);
	assert(xs.inters[0].object.type == E_PLANE);
}

static void intersect_with_ray_from_below()
{
	t_object p = ft_plane();
	t_ray	r = ft_ray(point(0, -1, 0), vector(0, 1, 0));

	t_xs xs = local_plane_intersect(p, r);
	assert(xs.count == 1);
	assert(xs.inters[0].t == 1);
	assert(xs.inters[0].object.type == E_PLANE);
}

void	test_plane()
{
	printf("=> plane normal test: ");
	normal_of_plane_is_constrant();
	printf("OK\n");
	printf("=> plane intersection test: ");
	intersect_with_ray_parallel_to_plane();
	intersect_with_coplanar_ray();
	intersect_with_ray_from_above();
	intersect_with_ray_from_below();
	printf("OK\n");
}
