#include "raytracer.h"

static t_uobject	*ft_content(t_list *node)
{
	if (!node)
		return ((void*)0);
	return (node->content);
}

void	ft_look_inters(t_list *head, t_ray ray, t_info *info)
{
	while (head)
	{
		if (head->type == E_SPHERE)
			ft_solve_sphere(ray, ft_content(head)->sphere, info);
		head = head->next;
	}
}

static void	per_pixel(const t_pair pair, t_canvas canvas, t_vcamera vcamera, t__data *data)
{
	t_ray		ray;
	t_info		info;

	ray = ft_setray(vcamera, pair);
	info.color.raw = 0;
	info.t = -1;
	ft_look_inters(data->objects, ray, &info);
	ft_write_pixel(canvas, pair.x, pair.y, info.color);
}

void	render(t__data *data)
{
	t_canvas	canvas;
	t_pair		pair;
	t_vcamera	vcamera;

	(void)data;
	pair = (t_pair){{0, 0}};
	canvas = ft_canvas(WIDTH, HEIGHT);
	vcamera = ft_setup_camera(data->camera);
	while (pair.y < HEIGHT)
	{
		pair.x = 0;
		while (pair.x < WIDTH)
		{
			per_pixel(pair, canvas, vcamera, data);
			pair.x++;
		}
		pair.y++;
	}
	ft_show_canvas(canvas);
	mlx_loop(canvas.mlx_ptr);
}
