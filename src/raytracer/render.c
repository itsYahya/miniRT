#include "raytracer.h"

t_canvas	render(t_camera c, t_scene s)
{
	t_canvas	canvas;
	int			x;
	int			y;
	t_ray		r;
	t_color		color;

	canvas = ft_canvas(c.hsize, c.vsize);
	y = -1;
	while (++y < c.vsize)
	{
		x = -1;
		while (++x < c.hsize)
		{
			r = ray_for_pixel(c, x, y);
			color = color_at(s, r);
			ft_write_pixel(canvas, x, y, to_raw_color(color));
		}
	}
	return (canvas);
}
