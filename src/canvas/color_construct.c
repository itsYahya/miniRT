#include "canvas.h"
#include <stdio.h>

t_color		ft_color(float r, float g, float b)
{
	if (r < 0 || r > 1 || g < 0 || g > 1 || b < 0 || b > 1)
		printf("Color values must be between 0 and 1\n");
	return (t_color){{r, g, b, 1}};
}

bool 		color_equal(t_color c1, t_color c2)
{
	return (c1.r == c2.r && c1.g == c2.g && c1.b == c2.b);
}

uint32_t	to_raw_color(t_color c)
{
	uint32_t	red;
	uint32_t	green;
	uint32_t	blue;

	red = (uint32_t)(c.r * 255) << 16;
	green = (uint32_t)(c.g * 255) << 8;
	blue = (uint32_t)(c.b * 255);
	return (0xff000000 | red | green | blue);
}

t_color	ft_hexcolor(uint32_t color)
{
	float	red;
	float	green;
	float	blue;

	red = (float)((color & 0x00ff0000) >> 16) / 255;
	green = (float)((color & 0x0000ff00) >> 8) / 255;
	blue = (float)(color & 0x000000ff) / 255;
	return (t_color){{red, green, blue, 1}};
}
