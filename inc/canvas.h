#ifndef CANVAS_H
# define CANVAS_H

# include "tuple.h"

// typedef union u_rgba t_rgba;
// union u_rgba
// {
// 	uint32_t	color;

// 	struct canvas
// 	{
// 		uint8_t b;
// 		uint8_t g;
// 		uint8_t r;
// 		uint8_t a;
// 	};

// };


t_tuple	color(float r, float g, float b);
t_tuple	hadamard_product(t_tuple c1, t_tuple c2);

#endif
