#include "raytracer.h"
#include "utils.h"

t_tuple			reflect(t_tuple v, t_tuple normal)
{
	return subst_tuple(v, multiply_tuple(normal, dot(v, normal) * 2));
}

void	ft_shading(t__data *data, t_info *info, t_tuple viewDir)
{
	t_tuple	obj_color = color2tuple(info->color);
	t_tuple	light_color = color2tuple(data->light.color);
	t_tuple	ambient_color = color2tuple(data->ambient.color);

	// ambient
	t_tuple	ambient = tuple_product(light_color, ambient_color);
	ambient = multiply_tuple(light_color, data->ambient.ratio);

	// diffuse
	t_tuple lightDir = normalize(subst_tuple(data->light.point, info->point));
	float diffuseStrength = ft_max(0, dot(info->normal, lightDir)) * data->light.bRatio;
	t_tuple	diffuse = multiply_tuple(light_color, diffuseStrength);

	// specular
	float materialSpecular = 1;
	float materialShininess = 200;
	t_tuple reflectDir = reflect(negate_tuple(lightDir), info->normal);
	float spec = pow(ft_max(dot(viewDir, reflectDir), 0.0), materialShininess);
	t_tuple specular = multiply_tuple(light_color, spec * materialSpecular);

	// combine
	t_tuple	factor = add_tuple(add_tuple(ambient, diffuse), specular);
	if (factor.x < -1 || factor.y < -1 || factor.z < -1)
		printf("error\n");
	if (factor.x > 1)
		factor.x = 1;
	if (factor.y > 1)
		factor.y = 1;
	if (factor.z > 1)
		factor.z = 1;
	t_tuple	result = tuple_product(factor, obj_color);
	info->color = tuple2color(result);
}
