#include "tests.h"

static void	test_parse_color()
{
	t_color c = get_color("255,255,255");
	assert(c.r == 1.0);
	assert(c.g == 1.0);
	assert(c.b == 1.0);
	assert(c.a == 0.0);
	c = get_color("255,125,0");
	assert(c.g == 0.49);
	c = get_color("10,0,255");
	assert(c.r == 0.04);
	assert(c.g == 0.0);
	assert(c.b == 1.0);
	assert(c.a == 0.0);
}

void test_parser()
{
	printf("=> parse color test: ");
	test_parse_color();
	printf("OK\n");
}
