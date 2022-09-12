#ifndef RAY_H
#define RAY_H

#include "tuple.h"

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

typedef struct s_vcamera
{
	t_tuple	origin;
	t_tuple	up;
	t_tuple	right;
	t_tuple	forward;
	float	h;
	float	w;
	float	ar;
}	t_vcamera;


#endif
