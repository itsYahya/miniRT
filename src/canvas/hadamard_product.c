#include "canvas.h"

t_tuple	hadamard_product(t_tuple c1, t_tuple c2)
{
	return color(
		c1.r * c2.r,
		c1.g * c2.g,
		c1.b * c2.b
	);
}
