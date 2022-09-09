#include "canvas.h"

void		ft_write_pixel(t_canvas c, int x, int y, uint32_t color)
{
	(*ft_pixel_at(c, x, y)) = color;
}

uint32_t*	ft_pixel_at(t_canvas c, int x, int y)
{
	return (c.img_data + c.width * y + x);
}


t_canvas	ft_canvas(float width, float height)
{
	t_canvas	canvas;
	int			temp;

	canvas.width = width;
	canvas.height = height;
	canvas.mlx_ptr = mlx_init();
	canvas.mlx_win = mlx_new_window(canvas.mlx_ptr, width, height, "Hello world!");
	canvas.img = mlx_new_image(canvas.mlx_ptr, width, height);
	canvas.img_data = (uint32_t *)mlx_get_data_addr(canvas.img, &temp, &temp, &temp);
	return (canvas);
}

void	destroy_canvas(t_canvas canvas)
{
	(void)canvas;
	// TODO
}
