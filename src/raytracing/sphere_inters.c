#include "miniRT.h"
#include "canvas.h"
#include "pair.h"
#include <stdio.h>
#include "ray.h"
#include "objects.h"

typedef struct s_paramerers
{
	float	a;
	float	b;
	float	c;
	float	delta;
}	t_param;

t_color	*ft_results(t_param param, t_sphere sphere, t_color *color, float *t)
{
	float rs1, rs2;

	rs1 = -1 * param.b + sqrt(param.delta);
	rs1 = rs1 / (2 * param.a);
	rs2 = -1 * param.b - sqrt(param.delta);
	rs2 = rs2 / (2 * param.a);
	if (rs1 >= 0 && rs1 <= rs2)
	{
		if (rs1 > *t && *t > 0)
			return (color);
		color->raw = sphere.color;
		*t = rs1;
	}
	else if (rs2 >= 0 && rs2 < rs1)
	{
		if (rs2 > *t && *t > 0)
			return (color);
		color->raw = sphere.color;
		*t = rs1;
	}
	return (color);
}	

void	ft_solve_sphere(const t_ray ray, t_sphere sphere, float *t, t_color *color)
{
	t_tuple	vect;
	t_param param;

	(void)t;
	param.a = dot(ray.direction, ray.direction);
	vect = subst_tuple(ray.origin, point(sphere.center.x, sphere.center.y, sphere.center.z));
	param.b = dot(vect, ray.direction)  * 2;
	param.c = dot(vect, vect) - pow(sphere.diameter, 2);
	param.delta = pow(param.b, 2) - 4 * param.a * param.c;
	if (param.delta >= 0)
		color = ft_results(param, sphere, color, t);
}
