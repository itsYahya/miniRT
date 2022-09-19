#include "algebra.h"
#include "tuple.h"
#include <stdlib.h>
#include <math.h>

t_tuple	point(double x, double y, double z)
{
	return tuple(x, y, z, 1);
}

t_tuple	vector(double x, double y, double z)
{
	return tuple(x, y, z, 0);
}

t_tuple tuple(double x, double y, double z, double w)
{
	return (t_tuple) {{x, y, z, w}};
}
