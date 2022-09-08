#include "canvas.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include "timer.h"
#include <pthread.h>

void	renderer()
{
	t_canvas	canvas;
	int			i;
	int			j;
	t_color	color;

	canvas = ft_canvas(600, 500);
	color.raw = 0xff0000ff;
	i = -1;
	while (++i < canvas.height)
	{
		j = -1;
		while (++j < canvas.width)
			ft_write_pixel(canvas, j, i, ft_color(0, 0, 255));
	}
	ft_show_canvas(canvas);
	mlx_loop(canvas.mlx_ptr);
}
