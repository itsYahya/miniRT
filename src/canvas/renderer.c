#include "canvas.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include "timer.h"
#include <pthread.h>
#include "pair.h"
#include "transform.h"
#include "raytracer.h"

# define WIDTH 480
# define HEIGHT 480


static void ft_draw_point(t_canvas canvas, float x, float y, uint32_t color)
{
	int	i;

	i = 0;
	ft_write_pixel(canvas, x, y, color);
	while (++i < 12)
	{
		ft_write_pixel(canvas, x + i, y, color);
		ft_write_pixel(canvas, x, y + i, color);
		ft_write_pixel(canvas, x, y - i, color);
		ft_write_pixel(canvas, x - i, y, color);

		ft_write_pixel(canvas, x + i, y + i, color);
		ft_write_pixel(canvas, x - i, y + i, color);
		ft_write_pixel(canvas, x - i, y - i, color);
		ft_write_pixel(canvas, x + i, y - i, color);
	}
}

t_canvas	ft_clock_canvas()
{
	t_canvas	canvas;
	float		clock_radius;
	int			i;

	canvas = ft_canvas(WIDTH, HEIGHT);
	clock_radius = (1.0f / 2.0f) * 600.0f;
	t_tuple	pts[12];

	i = -1;
	while (++i < 12)
	{
		pts[i] = matrix_tuple_multiply(
			rotate_y(i * M_PI / 6),
			point(0, 0, 1)
		);
	}
	// draw origin point
	ft_draw_point(canvas, WIDTH / 2, HEIGHT / 2, 0xffff00ff);

	i = -1;
	while (++i < 12)
	{
		// map points values from -1 -> 1 to 0 -> (WIDTH, HEIGHT)
		pts[i].x = clock_radius * ((pts[i].x / 2.0f) + 0.5) + (WIDTH - clock_radius) / 2;
		pts[i].z = clock_radius * ((pts[i].z / 2.0f) + 0.5) + (HEIGHT - clock_radius) / 2;
		ft_draw_point(canvas, pts[i].x, pts[i].z, 0xffffffff);
	}
	return (canvas);
}

t_canvas	ft_simple_sphere()
{
	float x, y;
	float world_x, world_y;
	t_tuple	position;
	const float wall_size = 10;
	const float wall_z = 10;
	const float canvas_pixels = WIDTH;
	const float pixel_size = wall_size / canvas_pixels;
	const float half = wall_size / 2;

	t_tuple ray_origin = point(0, 0, -5);
	t_canvas canvas = ft_canvas(WIDTH, HEIGHT);
	t_object shape = ft_sphere();
	y = -1;
	while (++y < canvas_pixels)
	{
		world_y = half - y * pixel_size;
		x = -1;
		while (++x < canvas_pixels)
		{
			world_x = -half + x * pixel_size;
			position = point(world_x, world_y, wall_z);
			t_xs xs = ft_intersect(shape, ft_ray(ray_origin, normalize(subst_tuple(position, ray_origin))));
			if (ft_hit(xs).t >= 0)
				ft_write_pixel(canvas, x, y, to_raw_color(ft_color(255, 0, 0)));
		}
	}
	return (canvas);
}

void	renderer()
{
	t_canvas	canvas_clock;

	canvas_clock = ft_simple_sphere();
	ft_show_canvas(canvas_clock);
	mlx_loop(canvas_clock.mlx_ptr);
}
