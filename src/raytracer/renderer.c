#include "raytracer.h"
#include "h_threads.h"

void	ft_look_inters(t_list *head, t_ray ray, t_info *info)
{
	t_object	obj;

	init_info(info);
	while (head)
	{
		obj = lst_object(head);
		if (obj.type == E_SPHERE)
			ft_solve_sphere(ray, obj, info);
		else if (obj.type == E_CYLINDER)
			cylinder_intersect(obj, ray, info);
		else if (obj.type == E_PLANE)
			ft_solve_plane(ray, obj, info);
		else if (obj.type == E_CONE)
			cone_intersect(obj, ray, info);
		head = head->next;
	}
}

static t_color	calculate_color(const t_fpair pair, t_vcamera vcamera, t__data *data)
{
	t_ray		ray;
	t_info		info;

	ray = ft_setray(vcamera, pair);
	ft_look_inters(data->objects, ray, &info);
	if (info.t > 0)
	{
		if (dot(info.normal, negate_tuple(ray.direction)) <= 0)
			info.normal = negate_tuple(info.normal);
		info.normal = normalize(info.normal);
		info.point = add_tuple(info.point, multiply_tuple(info.normal, EPSILON));
		info.eyeV = negate_tuple(ray.direction);
	}
	return (ft_shading(data, &info));
}

static t_color	ft_getcolor_average(t_color *colors, int rays)
{
	int		i;
	float	r;
	float	g;
	float	b;

	r = 0.0f;
	g = 0.0f;
	b = 0.0f;
	i = 0.0f;
	while (i < rays)
	{
		r += colors[i].r;
		g += colors[i].g;
		b += colors[i].b;
		i++;
	}
	return (ft_color(r / (float)rays, g / (float)rays, b / (float)rays));
}

static void	per_pixel(const t_fpair pair, t_canvas canvas, t_vcamera vcamera, t__data *data)
{
	t_color	color[16];
	t_fpair	iter;
	float	step;
	int		i;

	iter.i = 0;
	step = (float)1 / 2;
	i = 0;
	while (iter.i < 1)
	{
		iter.j = 0;
		while (iter.j < 1)
		{
			color[i++] = calculate_color((t_fpair){{pair.x + iter.j, pair.y + iter.i}}, vcamera, data);
			iter.j += step;
		}
		iter.i += step;
	}
	color[0] = ft_getcolor_average(color, 4);
	ft_write_pixel(canvas, pair.x, pair.y, color[0]);
}

void	*render(void *ptr)
{
	t_pair		pair;
	t_vcamera	vcamera;
	t__data		*data;
	t_thread	*thread;

	thread = (t_thread *)ptr;
	data = thread->data;
	pair = (t_pair){{0, thread->begin}};
	vcamera = thread->vcamera;
	while (pair.y < thread->end && errno == 0)
	{
		pair.x = 0;
		while (pair.x < WIDTH && errno == 0)
		{
			per_pixel((t_fpair){{pair.x, pair.y}}, data->canvas, vcamera, data);
			pair.x++;
		}
		pair.y++;
	}
	return (NULL);
}
