#include "canvas.h"

t_color		ft_color(uint8_t r, uint8_t g, uint8_t b)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = 1;
	return (color);
}

bool 		color_equal(t_color c1, t_color c2)
{
	return (c1.r == c2.r && c1.g == c2.g && c1.b == c2.b);
}
