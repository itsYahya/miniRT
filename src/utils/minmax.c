#include "utils.h"

float	ft_max(float a, float b)
{
	if (a < b)
		return (b);
	return (a);
}

float	ft_min(float a, float b)
{
	if (a < b)
		return (a);
	return (b);
}
