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
		else if (head->type == E_PLANE)
			ft_solve_plane(ray, ft_content(head)->plane, info);
		head = head->next;
	}
}

t_tuple	vectotuple(t_vect3 vec)
{
	return (tuple(vec.x, vec.y, vec.z, 0));
}

void	ft_shading(t__data *data, t_info *info)
{
	t_tuple	v_light;
	t_tuple	p_light;
	t_ray	ray;
	t_info	shade;
	float	d;

	p_light = vectotuple(data->light.point);
	v_light = subst_tuple(p_light, info->point);
	ray.direction = v_light;
	ray.origin = info->point;
	shade.t = -1;
	d = (dot(normalize(v_light), info->normal));
	if (d < 0)
		d = 0;
	ft_look_inters(data->objects, ray, &shade);
	if (shade.t == -1)
	{
		t_color c;
		c.raw = data->ambient.color;
		info->color.r = info->color.r * d;
		if (info->color.r > 255)
			info->color.r = 255;
		info->color.g = info->color.g * d;
		if (info->color.g > 255)
			info->color.g = 255;
		info->color.b = info->color.b * d;
		if (info->color.b > 255)
			info->color.b = 255;
	}
	else
		info->color.raw = 0;
}

static void	per_pixel(const t_pair pair, t_canvas canvas, t_vcamera vcamera, t__data *data)
{
	t_ray		ray;
	t_info		info;

	ft_setray(vcamera, &ray, pair);
	info.color.raw = 0x00ffffff;
	info.t = -1;
	ft_look_inters(data->objects, ray, &info);
	if (info.t != -1)
		ft_shading(data, &info);
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
