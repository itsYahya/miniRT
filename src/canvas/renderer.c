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

	canvas = ft_canvas(600, 500);
	mlx_loop(canvas.mlx_ptr);
}
