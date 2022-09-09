#include "canvas.h"

t_color		ft_hadamard_product(t_color c1, t_color c2)
{
	return ft_color(
		c1.r * c2.r,
		c1.g * c2.g,
		c1.b * c2.b
	);
}
