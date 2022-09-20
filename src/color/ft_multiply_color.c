#include "color.h"

t_color	ft_multiply_color(t_color color, t_tuple scaler)
{
	t_color	comb;

	comb.r = color.r * scaler.x;
	comb.g = color.g * scaler.y;
	comb.b = color.b * scaler.z;
	return (comb);
}
