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
