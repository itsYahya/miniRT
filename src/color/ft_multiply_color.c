#include "color.h"

t_color	ft_multiply_color(t_color color, double ratio)
{
	t_color	comb;

	comb.r = color.r * ratio;
	comb.g = color.g * ratio;
	comb.b = color.b * ratio;
	return (comb);
}
