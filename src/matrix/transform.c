#include "matrix.h"

t_matrix	translate(double x, double y, double z)
{
	return (t_matrix){{
		1, 0, 0, x,
		0, 1, 0, y,
		0, 0, 1, z,
		0, 0, 0, 1
	}};
}

t_matrix	scale(double x, double y, double z)
{
	return (t_matrix){{
		x, 0, 0, 0,
		0, y, 0, 0,
		0, 0, z, 0,
		0, 0, 0, 1
	}};
}

t_matrix	rotate_x(double radians)
{
	return (t_matrix){{
		1, 0,				0, 				0,
		0, cos(radians),	-sin(radians),	0,
		0, sin(radians),	cos(radians),	0,
		0, 0,				0,				1
	}};
}

t_matrix	rotate_y(double radians)
{
	return (t_matrix){{
		cos(radians),	0,	sin(radians),	0,
		0,				1,	0,				0,
		-sin(radians),	0,	cos(radians),	0,
		0,				0,	0,				1
	}};
}

t_matrix	rotate_z(double radians)
{
	return (t_matrix){{
		cos(radians),	-sin(radians),	0,	0,
		sin(radians),	cos(radians),	0,	0,
		0,				0,				1,	0,
		0,				0,				0,	1
	}};
}
