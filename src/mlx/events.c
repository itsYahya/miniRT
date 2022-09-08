#include "canvas.h"
#include "mlx.h"
#include "miniRT.h"
#include <stdlib.h>
#include <stdio.h>

static int close(void *data)
{
	t__data *data_ = (t__data *)data;
	int	i = 0;
	if (i)
		printf("hello %f\n", data_->camera.fov);
	exit(0);
}

int	key_ev(int key, t_canvas *canva)
{
	(void)canva;
	(void)key;

	return (0);
}

void	ft_setup_mlxevnets(void *win, t__data *data, t_canvas canvas)
{
	mlx_hook(win, 17, 0, close, data);
	mlx_hook(win, 2, 0, key_ev, &canvas);
}
