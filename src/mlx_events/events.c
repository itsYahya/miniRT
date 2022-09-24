#include "parser_.h"
#include <stdio.h>
#include <stdlib.h>
#include "canvas.h"
#include "miniRT.h"

static int onClose(void *data)
{
	ft_destroy(data);
	return (exit(0), 0);
}

void	setup_mlxevents(t__data *data)
{
	if (! data || ! data->canvas.mlx_win)
	{
		printf("failed to setup mlx events\n");
		return ;
	}
	mlx_hook(data->canvas.mlx_win, 17, 0, onClose, data);
}
