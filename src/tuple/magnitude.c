#include "tuple.h"

double magnitude(t_tuple v)
{
	return sqrt(
		pow(v.x, 2)
		+ pow(v.y, 2)
		+ pow(v.z, 2)
		+ pow(v.w, 2)
	);
}
