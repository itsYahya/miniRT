#include "tests.h"

t_tuple result;
t_matrix m;
double x_angle;
double z_angle;

# define TEST_ORIENTATION(ORG) \
	m = orientation_transform(point(0, 0, 0), ORG); \
	result = matrix_tuple_multiply(m, vector(0, 1, 0)); \
	if (! equal(angle_between(result, ORG), 0.0)) \
	{ \
		printf("\n"); \
		x_angle = ft_xangle(ORG); \
		z_angle = ft_zangle(ORG, x_angle); \
		printf("result_mag: %f\n", magnitude(result));\
		printf("org_mag: %f\n", magnitude(ORG));\
		printf("dot: %f\n", dot(result, ORG)); \
		printf("angle_between: %f\n", angle_between(result, ORG)); \
		printf("result: "); print_tuple(result); \
		printf("org: "); print_vector(ORG); \
		printf("x_angle: %f\n", rad2deg(x_angle)); \
		printf("z_angle: %f\n", rad2deg(z_angle)); \
	} \
	assert(equal(angle_between(result, ORG), 0.0));

void	test_orientation_transform()
{
	printf("=> test_orientation_transform test: ");
	TEST_ORIENTATION(vector(0, 0, 1));
	TEST_ORIENTATION(vector(0, 0, -1));
	TEST_ORIENTATION(vector(1, 0, 0));
	TEST_ORIENTATION(vector(-1, 0, 0));
	TEST_ORIENTATION(vector(1, 1, 0));
	TEST_ORIENTATION(vector(-1, -1, 0));
	TEST_ORIENTATION(vector(1, 0, 1));
	TEST_ORIENTATION(vector(1, 0, -1));
	TEST_ORIENTATION(vector(0, 1, 1));
	TEST_ORIENTATION(vector(1, 1, 1));
	TEST_ORIENTATION(vector(-1, -1, -1));
	TEST_ORIENTATION(vector(0.1, 0.4, 0.7));
	TEST_ORIENTATION(vector(-0.5, -1, -1));
	TEST_ORIENTATION(vector(-0.5, -1, -0.5));
	printf("OK\n");
}
