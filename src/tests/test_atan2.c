#include "tests.h"
#include <math.h>

double rad2deg(double rad)
{
	return (rad * 180) / M_PI;
}

static void	test_roation_x()
{
	double a = atan2(1, 1);
	assert(rad2deg(a) == 45.0);

	a = atan2(0.5, 1);
	assert(rad2deg(a) < 45.0);

	a = atan2(1, 0.5);
	assert(rad2deg(a) > 45.0);
	assert(rad2deg(a) < 90.0);

	a = atan2(-1, 1);
	assert(rad2deg(a) == -45.0);
	a = atan2(-1, 0.5);
	assert(rad2deg(a) < -45.0);
	assert(rad2deg(a) > -90.0);

	a = atan2(-1, -0.5);
	assert(rad2deg(a) < -90.0);
	assert(rad2deg(a) > -135.0);

	a = atan2(1, -1);
}

static void	test_rotation_y()
{
	double a = -M_PI_2 + atan2(1, 0.5);
	assert(rad2deg(a) < 0.0);
	assert(rad2deg(a) > -45.0);
	a = -M_PI_2 + atan2(1, -1);
	assert(rad2deg(a) == 45.0);
}

void test_atan2()
{
	printf("=> atan2 test: ");
	test_roation_x();
	test_rotation_y();
	printf("OK\n");
}
