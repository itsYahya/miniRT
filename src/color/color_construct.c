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

	color.r = (tuple.x * 0.5f + 0.5f) * (float)255.0f;
	color.g = (tuple.y * 0.5f + 0.5f) * (float)255.0f;
	color.b = (tuple.z * 0.5f + 0.5f) * (float)255.0f;
	color.a = 0;
	return (color);
}
