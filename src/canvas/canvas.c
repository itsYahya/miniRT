#include "canvas.h"
#include "miniRT.h"

void	ft_write_pixel(t_canvas c, int x, int y, t_color color)
{
	(*ft_pixel_at(c, x, y)) = raw_color(color);
}

uint32_t*	ft_pixel_at(t_canvas c, int x, int y)
{
	return (c.img_data + c.width * y + x);
}

int	ft_canvas(t_canvas *canvas, float width, float height)
{
	int			temp;

	canvas->width = width;
	canvas->height = height;
	canvas->mlx_ptr = mlx_init();
	if (! canvas->mlx_ptr)
		return (errno = 1, 0);
	canvas->mlx_win = mlx_new_window(canvas->mlx_ptr, width, height, "Hello world!");
	if (! canvas->mlx_win)
		return (errno = 1, 0);
	canvas->img = mlx_new_image(canvas->mlx_ptr, width, height);
	if (! canvas->img)
		return (errno = 1, 0);
	canvas->img_data = (uint32_t *)mlx_get_data_addr(canvas->img, &temp, &temp, &temp);
	return (0);
}

void	ft_show_canvas(t_canvas canvas)
{
	mlx_put_image_to_window(canvas.mlx_ptr, canvas.mlx_win, canvas.img, 0, 0);
}

void	destroy_canvas(t_canvas canvas)
{
	if (canvas.mlx_ptr && canvas.img)
		mlx_destroy_image(canvas.mlx_ptr, canvas.img);
	if (canvas.mlx_ptr && canvas.mlx_win)
		mlx_destroy_window(canvas.mlx_ptr, canvas.mlx_win);
}
