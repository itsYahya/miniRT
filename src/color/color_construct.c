#include "canvas.h"

t_color		ft_color(float r, float g, float b)
{
	return ((t_color){{r, g, b, 0.0}});
}

static void	check_value(float *c)
{
	if (*c > 1.0)
		*c = 1.0;
	else if (*c < 0.0)
		*c = 0.0;
}

uint32_t	raw_color(t_color c)
{
	uint32_t	red;
	uint32_t	green;
	uint32_t	blue;
	uint32_t	alpha;

	check_value(&c.r);
	check_value(&c.g);
	check_value(&c.b);
	check_value(&c.a);
	alpha = (uint32_t)(c.a * 255) << 24;
	red = (uint32_t)(c.r * 255) << 16;
	green = (uint32_t)(c.g * 255) << 8;
	blue = (uint32_t)(c.b * 255);
	return (alpha | red | green | blue);
}

t_color		to_color(uint32_t raw_value)
{
	float	r;
	float	g;
	float	b;

	r = (float)((raw_value & 0x00ff0000) >> 16) / 255;
	g = (float)((raw_value & 0x0000ff00) >> 8) / 255;
	b = (float)((raw_value & 0x000000ff)) / 255;
	return ((t_color){{r, g, b, 0}});
}

void	print_color(t_color c)
{
	printf("r: %f, g: %f, b: %f, a: %f\n", c.r, c.g, c.b, c.a);
}
