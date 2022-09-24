#include "raytracer.h"

static t_tuple	ft_reflect(t_tuple light_vect, t_info *info)
{
	t_tuple	reflect;
	float	d;

	d = ft_cos(light_vect, info->normal);
	reflect = multiply_tuple(info->normal, 2 * d);
	reflect = subst_tuple(reflect, light_vect);
	reflect = normalize(reflect);
	return (reflect);
}

static float	ft_scaler(t_tuple reflect, t_tuple view, t_material material)
{
	float	scaler;

	scaler = pow(ft_cos(reflect, view), material.shininess);
	return (material.specular * scaler);
}

t_color	ft_specular(t_shader *shader, t_info *info, t_tuple view)
{
	t_color	specular;
	t_tuple	reflect;
	float	ratio;

	reflect = ft_reflect(shader->light_vect, info);
	ratio = ft_scaler(reflect, view, info->material);
	specular = ft_merge_color(info->color, shader->light_color, ratio * shader->light_ratio);
	return (specular);
}
