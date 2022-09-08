#include "raytracer.h"
#include <stdarg.h>
#include <stdlib.h>
#include "mutils.h"
#include "pair.h"

t_object ft_sphere()
{
	return (t_object){};
}

t_ray	ft_ray(t_tuple origin, t_tuple direction)
{
	return (t_ray){
		origin,
		direction
	};
}

t_tuple	ft_position(t_ray r, float t)
{
	return add_tuple(r.origin, multiply_tuple(r.direction, t));
}

t_xs	ft_intersect(t_object sphere, t_ray ray)
{
	struct
	{
		float	a;
		float	b;
		float	c;
	}		f;
	t_tuple			sphere_to_ray;
	float			discripminant;
	t_intersection	t1;
	t_intersection	t2;

	(void)sphere;
	sphere_to_ray = subst_tuple(ray.origin, point(0, 0, 0));
	f.a = dot(ray.direction, ray.direction);
	f.b = 2 * dot(ray.direction, sphere_to_ray);
	f.c = dot(sphere_to_ray, sphere_to_ray) - 1;
	discripminant = pow(f.b, 2) - 4 * f.a * f.c;
	if (discripminant < 0)
		return (t_xs){0};
	t1 = ft_intersection((-f.b - sqrt(discripminant)) / (2 * f.a), sphere);
	t2 = ft_intersection((-f.b + sqrt(discripminant)) / (2 * f.a), sphere);
	if (discripminant == 0)
		return ft_intersections(1, t1);
	return ft_intersections(2, t1, t2);
}

t_intersection	ft_intersection(float t, t_object object)
{
	return (t_intersection){t, object};
}

t_xs	ft_intersections(unsigned int count, ...)
{
	va_list			ap;
	t_intersection	*arr;
	unsigned int	i;

	va_start(ap, count);
	arr = (t_intersection *)malloc(sizeof(t_intersection) * count);
	if (! arr)
		return ((t_xs){-1, NULL});
	i = -1;
	while (++i < count)
		arr[i] = va_arg(ap, t_intersection);
	va_end(ap);
	return ((t_xs){count, arr});
}

void	destroy_intersections(t_xs	*xs)
{
	if (! xs)
		return ;
	xs->inters = ft_free(xs->inters);
	xs->count = -1;
}

t_intersection	ft_hit(t_xs xs)
{
	t_intersection	inter;
	t_intersection	visible_inter;
	int				i;

	visible_inter = (t_intersection){-1, {}};
	i = -1;
	while (++i < xs.count)
	{
		inter = xs.inters[i];
		if (visible_inter.t < 0 || (inter.t > 0 && inter.t < visible_inter.t))
			visible_inter = inter;
	}
	return (visible_inter);
}
