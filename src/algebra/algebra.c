#include "algebra.h"

bool	equal(double a, double b)
{
	return fabs(a - b) < EPSILON;
}
