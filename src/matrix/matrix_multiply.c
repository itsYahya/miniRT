#include "matrix.h"
#include "tuple.h"

static float	calc_value(t_matrix mt1, t_matrix mt2, int x, int y)
{
	t_tuple	row;
	t_tuple col;

	row = tuple(
		mt1.raw[y][0],
		mt1.raw[y][1],
		mt1.raw[y][2],
		mt1.raw[y][3]
	);
	col = tuple(
		mt2.raw[0][x],
		mt2.raw[1][x],
		mt2.raw[2][x],
		mt2.raw[3][x]
	);
	return dot(row, col);
}

t_matrix	ft_matrix_multiply(t_matrix mt1, t_matrix mt2)
{
	t_matrix	result;
	int			x;
	int			y;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
			result.raw[y][x] = calc_value(mt1, mt2, x, y);
	}
	return (result);
}
