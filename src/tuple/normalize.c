#include "tuple.h"

t_tuple	normalize(t_tuple v)
{
	double	mangt;

	mangt = magnitude(v);
	return tuple(
		v.x / mangt,
		v.y / mangt,
		v.z / mangt,
		v.w / mangt
	);
}
