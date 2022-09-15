#include "color.h"

t_color	ft_multiply_color(t_color c1, t_color c2)
{
	t_color	comb;

	comb.r = c1.r * c2.r;
	comb.g = c1.g * c2.g;
	comb.b = c1.b * c2.b;
	return (comb);
}
