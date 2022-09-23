#include "tests.h"

t_object	cy;
t_ray		r;
t_xs		xs;
int			count;

# define INTERSECT(ORIGIN, DIR) \
	cy = infinite_cylinder(); \
	r = ft_ray(ORIGIN, DIR); \
	xs = local_cylinder_intersect(cy, r)

# define EXPECT_T(T0, T1) \
	assert(xs.inters[0].t == T0); \
	assert(xs.inters[1].t == T1); \
	destroy_inters(&xs)

# define EXPECT_COUNT(COUNT) \
	assert(xs.count == COUNT); \
	destroy_inters(&xs)

static void	test_ray_miss_cylinder()
{
	INTERSECT(point(1, 0, 0), vector(0, 1, 0));
	EXPECT_COUNT(0);
	INTERSECT(point(0, 0, 0), vector(0, 1, 0));
	EXPECT_COUNT(0);
	INTERSECT(point(0, 0, -5), vector(1, 1, 1));
	EXPECT_COUNT(0);
}

static void	test_ray_strikes_cylinder()
{
	INTERSECT(point(1, 0, -5), vector(0, 0, 1));
	assert(xs.count == 2);
	EXPECT_T(5, 5);

	INTERSECT(point(0, 0, -5), vector(0, 0, 1));
	assert(xs.count == 2);
	EXPECT_T(4, 6);

	INTERSECT(point(0.5, 0, -5), vector(0.1, 1, 1));
	assert(xs.count == 2);
	// printf("t0: %f, t1: %f\n", xs.inters[0].t, xs.inters[1].t);
	// EXPECT_T(6.80798, 7.08872);
}

static void	test_normal_on_cylinder()
{
    t_tuple	p;

    cy = infinite_cylinder();
    p = point(1, 0, 0);
    assert(is_equal(local_cylinder_normal(p), vector(1, 0, 0)));
    p = point(0, 5, -1);
    assert(is_equal(local_cylinder_normal(p), vector(0, 0, -1)));
    p = point(0, -2, 1);
    assert(is_equal(local_cylinder_normal(p), vector(0, 0, 1)));
    p = point(-1, 1, 0);
    assert(is_equal(local_cylinder_normal(p), vector(-1, 0, 0)));
}

# define INTERSECT_CONSTRAINED(ORIGIN, DIR) \
	cy = infinite_cylinder(); \
	cy.min_y = 1; \
	cy.max_y = 2; \
	r = ft_ray(ORIGIN, normalize(DIR)); \
	xs = local_cylinder_intersect(cy, r)
static void	test_intersect_constrained_cylinder()
{
	INTERSECT_CONSTRAINED(point(0, 1.5, 0),  vector(0.1, 1, 0));
	assert(xs.count == 0);
	INTERSECT_CONSTRAINED(point(0, 3, -5),  vector(0, 0, 1));
	assert(xs.count == 0);
	INTERSECT_CONSTRAINED(point(0, 0, -5),  vector(0, 0, 1));
	assert(xs.count == 0);
	INTERSECT_CONSTRAINED(point(0, 2, -5),  vector(0, 0, 1));
	assert(xs.count == 0);
	INTERSECT_CONSTRAINED(point(0, 1, -5),  vector(0, 0, 1));
	assert(xs.count == 0);
	INTERSECT_CONSTRAINED(point(0, 1.5, -2),  vector(0, 0, 1));
	assert(xs.count == 2);
}

void	test_cylinder()
{
	printf("=> cylinder test: ");
	test_ray_miss_cylinder();
	test_ray_strikes_cylinder();
    test_normal_on_cylinder();
	test_intersect_constrained_cylinder();
	printf("OK\n");
}
