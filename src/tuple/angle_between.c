#include "tuple.h"

double	angle_between(t_tuple v1, t_tuple v2)
{
	double v1_mag;
	double v2_mag;
	double result;

	v1_mag = magnitude(v1);
	v2_mag = magnitude(v2);
	if (equal(v1_mag, 0.0) || equal(v2_mag, 0.0))
		return (0.0);
	result = dot(v1, v2) / (v1_mag * v2_mag);
	if (result > 1)
		result = 1;
	else if (result < -1)
		result = -1;
	return acos(result);
}
