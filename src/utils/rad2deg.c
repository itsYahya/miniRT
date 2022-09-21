#include "utils.h"

double	rad2deg(double x)
{
	return (x * 180.0) / acos(-1);
}

double	deg2rad(double x)
{
	return (x * acos(-1)) / 180.0;
}
