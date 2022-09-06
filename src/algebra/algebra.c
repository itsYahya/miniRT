#include "algebra.h"

bool	equal(float a, float b)
{
	return fabs(a - b) < EPSILON;
}
