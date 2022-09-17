#ifndef COLOR_H
#define COLOR_H

#include "tuple.h"
#include <stdint.h>

typedef union u_color t_color;
union u_color
{
	uint32_t	raw;
	struct
	{
		uint8_t	b;
		uint8_t	g;
		uint8_t	r;
		uint8_t	a;
	};
};

t_color	ft_color(uint8_t r, uint8_t g, uint8_t b);
t_color	tuple2color(t_tuple tuple);
t_tuple color2tuple(t_color color);
t_color	ft_hadamard_product(t_color c1, t_color c2);
t_color	ft_scale_color(t_color color, double ratio);
t_color	ft_add_color(t_color c1, t_color c2);
t_color	ft_multiply_color(t_color c1, t_color c2);

#endif
