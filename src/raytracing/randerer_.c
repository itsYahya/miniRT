#include "canvas.h"
#include "pair.h"
#include <stdio.h>
#include "ray.h"
#include "objects.h"
#include "randerer.h"

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

	ft_setray(vcamera, &ray, pair);
	info.color.raw = 0x00ffffff;
	info.t = -1;
	ft_look_inters(data->objects, ray, &info);
	ft_write_pixel(canvas, pair.x, pair.y, info.color);
}

void	renderer_rt(t__data *data)
{
	t_canvas	canvas;
	t_pair		pair;
	t_vcamera	vcamera;

	(void)data;
	pair = (t_pair){{0, 0}};
	canvas = ft_canvas(WIDTH, HEIGHT);
	ft_setup_camera(&vcamera, data->camera);
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
