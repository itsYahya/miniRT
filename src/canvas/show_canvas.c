#include "canvas.h"

void	ft_show_canvas(t_canvas canvas)
{
	mlx_put_image_to_window(canvas.mlx_ptr, canvas.mlx_win, canvas.img, 0, 0);
}
