#include "tests.h"

t_object	cone;
t_tuple		direction;
t_ray		r;
t_xs		xs;
t_tuple		n;

# define INTERSECT(P, DIR) \
	cone = infinite_cone(); \
	direction = normalize(DIR); \
	r = ft_ray(P, direction); \
	xs = local_cone_intersect(cone, r)

# define T(index) xs.inters[index].t
# define COUNT xs.count

static void	test_intersect_cone_with_ray()
{
	INTERSECT(point(0, 0, -5), vector(0, 0, 1));
	assert(COUNT == 2);
	assert(T(0) == 5);
	assert(T(1) == 5);

	INTERSECT(point(0, 0, -5), vector(1, 1, 1));
	assert(COUNT == 2);
	assert(equal(T(0), 8.66025));
	assert(equal(T(1), 8.66025));

	INTERSECT(point(1, 1, -5), vector(-0.5, -1, 1));
	assert(COUNT == 2);
	assert(equal(T(0), 4.55006));
	assert(equal(T(1), 49.44994));
}

static void	test_intersect_cone_with_ray_parallel_to_one_of_its_halves()
{
	INTERSECT(point(0, 0, -1), vector(0, 1, 1));
	assert(COUNT == 1);
	// assert(T(0) == 0.35355);
	assert(equal(T(0), 0.707107));
}

# define EXPECT_NORMAL(POINT) \
	cone = infinite_cone(); \
	n = local_cone_normal(POINT)

static void	test_normal_on_cone()
{
	EXPECT_NORMAL(point(0, 0, 0));
	assert(is_equal(n, vector(0, 0, 0)));

	EXPECT_NORMAL(point(1, 1, 1));
	assert(is_equal(n, vector(1, -sqrt(2), 1)));

	EXPECT_NORMAL(point(-1, -1, 0));
	assert(is_equal(n, vector(-1, 1, 0)));
}

void	test_cone()
{
	printf("=> cone test: ");
	test_intersect_cone_with_ray();
	test_intersect_cone_with_ray_parallel_to_one_of_its_halves();
	test_normal_on_cone();
	printf("OK\n");
}
