#include "raytracer.h"

static t_tuple	vectotuple(t_vect3 vec)
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
	ft_intersect(data->objects, ray, &shade);
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

