#include "miniRT.h"
#include "canvas.h"
#include "pair.h"
#include <stdio.h>
#include "ray.h"
#include "objects.h"


static t_color get_color(const float x, const float y)
{
	t_color color;

	color.raw = 0;
	color.raw = (int)(x * 255) << 8 | (int)(y * 255) << 0;
	return (color);
}

// static t_sphere	ft_get_sphere(t_list *head)
// {
// 	t_sphere	sphere;

// 	while (head)
// 	{
// 		sphere = ((t_uobject *)head->content)->sphere;
// 		if (head->type == E_SPHERE)	
// 			break;
// 		head = head->next;
// 	}
// 	return (sphere);
// }

static void	per_pixel(const t_pair pair, t_canvas canvas, t_vcamera vcamera, t__data *data)
{
	t_ray	ray;
	t_color	color;
	float	t;
	t_list	*head;
	t_sphere	sphere;

	ft_setray(vcamera, &ray, pair);
	head = data->objects;
	color = get_color(pair.x/WIDTH, pair.y/HEIGHT);
	t = -1;
	while (head)
	{
		if (head->type != E_SPHERE)
		{
			head = head->next;
			continue;
		}
		sphere = ((t_uobject*)head->content)->sphere;
		ft_solve_sphere(ray, sphere, &t, &color);
		head = head->next;
	}
	ft_write_pixel(canvas, pair.x, pair.y, color);
}

void	renderer_rt(t__data *data)
{
	t_canvas	rt_cnvs;
	t_pair		pair;
	t_vcamera	vcamera;

	(void)data;
	pair = (t_pair){{0, 0}};
	rt_cnvs = ft_canvas(WIDTH, HEIGHT);
	ft_setup_camera(&vcamera, data->camera);
	while (pair.y < HEIGHT)
	{
		pair.x = 0;
		while (pair.x < WIDTH)
		{
			per_pixel(pair, rt_cnvs, vcamera, data);
			pair.x++;
		}
		pair.y++;
	}
	ft_show_canvas(rt_cnvs);
	mlx_loop(rt_cnvs.mlx_ptr);
}
