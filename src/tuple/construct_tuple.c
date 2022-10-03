#include "algebra.h"
#include "tuple.h"
#include <stdlib.h>
#include <math.h>

t_tuple	point(float x, float y, float z)
{
	return tuple(x, y, z, 1);
}

t_tuple	vector(float x, float y, float z)
{
	return tuple(x, y, z, 0);
}

t_tuple tuple(float x, float y, float z, float w)
{
	return (t_tuple) {{x, y, z, w}};
}
