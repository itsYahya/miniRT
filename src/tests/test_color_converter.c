#include "tests.h"

# define EPSILON_3 0.000001

static void	test_raw_to_color()
{
	uint32_t	value;
	t_color		color;
	t_color		expected;

	value = 0x00ff0000;
	color = to_color(value);
	assert(color.a == 0.0);
	assert(color.r == 1.0);
	assert(color.g == 0.0);
	assert(color.b == 0.0);

	expected = ft_color(196.0 / 255.0, 85.0 / 255.0, 77.0 / 255.0);
	color = to_color(raw_color(expected));
	assert(equal(color.a, 0.0f));
	assert(equal(color.r, expected.r));
	assert(equal(color.g, expected.g));
	assert(equal(color.b, expected.b));
}


void	test_color_converter()
{
	printf("=> convert color test: ");
	test_raw_to_color();
	printf("OK\n");
}
