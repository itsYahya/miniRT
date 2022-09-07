#include "transform.h"

t_matrix	translate(float x, float y, float z)
{
	return (t_matrix){{
		1, 0, 0, x,
		0, 1, 0, y,
		0, 0, 1, z,
		0, 0, 0, 1
	}};
}
