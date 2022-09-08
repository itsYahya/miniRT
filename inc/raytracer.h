#ifndef RAYTRACER_H
# define RAYTRACER_H

# include "tuple.h"

typedef struct s_ray t_ray;
struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
};

t_ray	ray(t_tuple origin, t_tuple direction);
t_tuple	position(t_ray r, float t);

#endif
