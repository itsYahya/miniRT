#include "raytracer.h"

double	ft_cos(t_tuple v1, t_tuple v2)
{
	double	d;

	d = (dot(v1, v2));
	d = ft_max(d, 0);
	return (d);
}

static void	ft_shader_init(t_info *info, t_shader *shdata, t_info *shade_info, t_light *light)
{
	shdata->light_point = light->point;
	shdata->light_vect = subst_tuple(shdata->light_point, info->point);
	shdata->light_color.raw = light->color;
	shdata->light_point = light->point;
	shdata->light_ratio = light->bRatio;
	shdata->ray.origin = info->point;
	shdata->ray.direction = shdata->light_vect;
	shade_info->t = -1;
}

static float	ft_distance(t_tuple p1, t_tuple p2)
{
	t_tuple	vect;
	float	mag;

	vect = subst_tuple(p1, p2);
	mag = magnitude(vect);
	return (mag);
}

void	ft_shading(t__data *data, t_info *info, t_ray ray)
{
	t_info		shade_info;
	t_shader	shade;
	float		d;
	t_list		*head;

	shade.ambient.raw = data->ambient.color;
	shade.am_ratio = data->ambient.ratio;
	shade.ambient = ft_merge_color(info->color, shade.ambient, shade.am_ratio);
	head = data->lights;
	shade.color.raw = 0;
	while (head)
	{
		ft_shader_init(info, &shade, &shade_info, head->content);
		ft_look_inters(data->objects, shade.ray, &shade_info);
		if (shade_info.t == -1 || ft_distance(shade.light_point, info->point) <= ft_distance(shade_info.point, info->point))
		{
			d = ft_cos(normalize(shade.light_vect), info->normal);
			shade.difuse = ft_merge_color(info->color, shade.light_color, d * shade.light_ratio);
			shade.specular = ft_specular(&shade, info, multiply_tuple(ray.direction, -1));
			shade.color = ft_add_color(ft_add_color(shade.difuse, shade.color), shade.specular);
		}
		head = head->next;
	}
	info->color = ft_add_color(shade.color, shade.ambient);
}
