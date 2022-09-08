#include "algebra.h"
#include "tuple.h"
#include <stdlib.h>
#include <math.h>

t_tuple	add_tuple(t_tuple pv, t_tuple v)
{
	return tuple(
		pv.x + v.x,
		pv.y + v.y,
		pv.z + v.z,
		pv.w + v.w
	);
}

t_tuple	subst_tuple(t_tuple p, t_tuple pv)
{
	return tuple(
		p.x - pv.x,
		p.y - pv.y,
		p.z - pv.z,
		p.w - pv.w
	);
}

t_tuple	negate_tuple(t_tuple v)
{
	return tuple(
		-v.x,
		-v.y,
		-v.z,
		-v.w
	);
}

t_tuple	multiply_tuple(t_tuple v, float scalar)
{
	return tuple(
		v.x * scalar,
		v.y * scalar,
		v.z * scalar,
		v.w * scalar
	);
}

t_tuple	divide_tuple(t_tuple v, float scalar)
{
	return tuple(
		v.x / scalar,
		v.y / scalar,
		v.z / scalar,
		v.w / scalar
	);
}
