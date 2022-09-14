#include "raytracer.h"
#include "tuple.h"
#include "matrix.h"

static void ft_draw_point(t_canvas canvas, float x, float y, t_color color)
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

static t_canvas	ft_clock_canvas()
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
	ft_draw_point(canvas, WIDTH / 2, HEIGHT / 2, (t_color){.raw = 0xffff00ff});

	i = -1;
	while (++i < 12)
	{
		// map points values from -1 -> 1 to 0 -> (WIDTH, HEIGHT)
		pts[i].x = clock_radius * ((pts[i].x / 2.0f) + 0.5) + (WIDTH - clock_radius) / 2;
		pts[i].z = clock_radius * ((pts[i].z / 2.0f) + 0.5) + (HEIGHT - clock_radius) / 2;
		ft_draw_point(canvas, pts[i].x, pts[i].z, (t_color){.raw = 0xffffffff});
	}
	return (canvas);
}

void	renderer()
{
	t_canvas	canvas_clock;

	canvas_clock = ft_clock_canvas();
	ft_show_canvas(canvas_clock);
	mlx_loop(canvas_clock.mlx_ptr);
}
