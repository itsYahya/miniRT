#ifndef COLOR_H
#define COLOR_H

# include "tuple.h"
# include <stdio.h>
# include <stdint.h>
# include "algebra.h"

typedef t_tuple t_color;

t_color		ft_color(double r, double g, double b);
t_color		ft_hexcolor(uint32_t color);
uint32_t	to_raw_color(t_color c);
bool 		color_equal(t_color c1, t_color c2);
void		print_color(t_color c);

#endif
