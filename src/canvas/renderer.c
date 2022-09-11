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
	t_object sphere = ft_sphere();
	sphere.material = ft_material();
	sphere.material.color = ft_color(0.5, 0.0, 1);
	t_light	light = point_light(point(-10, 10, -10), ft_color(1, 1, 1));
	y = -1;
	while (++y < canvas_pixels)
	{
		world_y = half - y * pixel_size;
		x = -1;
		while (++x < canvas_pixels)
		{
			world_x = -half + x * pixel_size;
			position = point(world_x, world_y, wall_z);
			t_ray ray = ft_ray(ray_origin, normalize(subst_tuple(position, ray_origin)));
			t_xs xs = ft_intersect(sphere, ray);
			t_intersection hit = ft_hit(xs);
			if (hit.t >= 0) {
				t_tuple	point = ft_position(ray, hit.t);
				t_tuple normalv = normal_at(hit.object, point);
				t_tuple eyev = negate_tuple(ray.direction);
				t_color color = ft_lighting(hit.object.material, light, point, eyev, normalv);
				ft_write_pixel(canvas, x, y, to_raw_color(color));
			}
		}
	}
	return (canvas);
}

void	renderer()
{
	t_canvas	canvas;

	canvas = ft_simple_sphere();
	ft_show_canvas(canvas);
	mlx_loop(canvas.mlx_ptr);
}
