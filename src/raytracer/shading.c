#include "raytracer.h"
 
double	ft_max(double f1, double f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

double	ft_cos(t_tuple v1, t_tuple v2)
{
	double	d;

	d = dot(v1, v2);
	d = ft_max(d, 0);
	return (d);
}

static void	ft_shader_init(t__data *data, t_info *info, t_shader *shdata, t_info *shade_info)
{
	shdata->light_point = data->light.point;
	shdata->light_vect = subst_tuple(shdata->light_point, info->point);
	shdata->ambient.raw = data->ambient.color;
	shdata->am_ratio = data->ambient.ratio;
	shdata->light_color.raw = data->light.color;
	shdata->light_point = data->light.point;
	shdata->light_ratio = data->light.bRatio;
	shdata->ray.origin = info->point;
	shdata->ray.direction = shdata->light_vect;
	shade_info->t = -1;
}

void	ft_shading(t__data *data, t_info *info, t_ray ray)
{
	t_info		shade_info;
	t_shader	shade;
	float	d;

	ft_shader_init(data, info, &shade, &shade_info);
	d = ft_cos(normalize(shade.light_vect), info->normal);
	ft_look_inters(data->objects, shade.ray, &shade_info);
	shade.ambient = ft_merge_color(info->color, shade.ambient, shade.am_ratio);
	if (shade_info.t == -1)
	{
		shade.difuse = ft_merge_color(info->color, shade.light_color, d * shade.light_ratio);
		shade.specular = ft_specular(&shade, info, multiply_tuple(ray.direction, -1));
		info->color = ft_add_color(ft_add_color(shade.difuse, shade.ambient), shade.specular);
	}
	else
		info->color = shade.ambient;
}

