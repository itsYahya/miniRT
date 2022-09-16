#include "color.h"

t_tuple	ft_map_color(t_color color)
{
	t_tuple	res;

	res.x = color.r / 255;
	res.y = color.g / 255;
	res.z = color.b / 255;
	return (res);
}
