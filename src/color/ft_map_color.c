#include "color.h"

t_color	ft_map_color(t_color color)
{
	t_color	res;

	res.r = color.r / 255;
	res.g = color.g / 255;
	res.b = color.b / 255;
	return (res);
}
