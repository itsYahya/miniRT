#include "raytracer.h"

static t_tuple	vectotuple(t_vect3 vec)
{
	return (tuple(vec.x, vec.y, vec.z, 0));
}

static double	ft_max(double f1, double f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

static double	ft_cos(t_tuple v1, t_tuple v2)
{
	double	d;

	d = dot(v1, v2);
	d = ft_max(d, 0);
	return (d);
}

t_color	ft_merge_color(t_color main, t_color add, float ratio)
{
	t_color	result;

	result.r = main.r * (add.r / 255) * ratio;
	result.g = main.g * (add.g / 255) * ratio;
	result.b = main.b * (add.b / 255) * ratio;
	return (result);
}

void	ft_shading(t__data *data, t_info *info)
{
	t_tuple	light_vect;
	t_tuple	light_point;
	t_ray	ray;
	t_info	shade_info;
	t_color	difuse;
	t_color light_color;
	t_color	ambient;
	float	d;

	light_point = vectotuple(data->light.point);
	light_vect = subst_tuple(light_point, info->point);
	ray.direction = light_vect;
	ray.origin = info->point;
	ambient.raw = data->ambient.color;
	light_color = data->light.color;
	shade_info.t = -1;
	d = ft_cos(normalize(light_vect), info->normal);
	ft_look_inters(data->objects, ray, &shade_info);
	ambient = ft_merge_color(info->color, ambient, data->ambient.ratio);
	if (shade_info.t == -1)
	{
		difuse = ft_merge_color(info->color, light_color, d * data->light.bRatio);
		info->color = ft_add_color(difuse, ambient);
	}
	else
		info->color = ambient;
}
