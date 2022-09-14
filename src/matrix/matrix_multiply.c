#include "matrix.h"

t_matrix	matrix_multiply(t_matrix mt1, t_matrix mt2)
{
	t_matrix	result;
	int			x;
	int			y;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
			result.raw[y][x] = dot(get_row(mt1, y), get_col(mt2, x));
	}
	return (result);
}
