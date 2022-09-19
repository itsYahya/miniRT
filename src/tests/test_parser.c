#include "tests.h"

static void	test_parse_color()
{
	t_color c = get_color("255,255,255");
	assert(c.r == 1.0f);
	assert(c.g == 1.0f);
	assert(c.b == 1.0f);
	assert(c.a == 0.0f);
	c = get_color("255,125,0");
	assert(c.g == 0.49f);
	c = get_color("10,0,255");
	assert(c.r == 0.04f);
	assert(c.g == 0.0f);
	assert(c.b == 1.0f);
	assert(c.a == 0.0f);
}

void test_parser()
{
	printf("=> parse color test: ");
	test_parse_color();
	printf("OK\n");
}
