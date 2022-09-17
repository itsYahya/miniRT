#include "color.h"

t_color		ft_color(uint8_t r, uint8_t g, uint8_t b)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = 1;
	return (color);
}

t_color	tuple2color(t_tuple tuple)
{
	t_color	color;

	color.r = tuple.x * (float)255.0f;
	color.g = tuple.y * (float)255.0f;
	color.b = tuple.z * (float)255.0f;
	color.a = 0;
	return (color);
}

t_tuple color2tuple(t_color color)
{
	return vector((float)color.r / 255.0f, (float)color.g / 255.0f, (float)color.b / 255.0f);
}
