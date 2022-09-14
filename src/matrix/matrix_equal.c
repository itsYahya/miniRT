#include "matrix.h"

bool	matrix_equal(t_matrix mt1, t_matrix mt2)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (! equal(mt1.raw[i][j], mt2.raw[i][j]))
				return false;
	}
	return (true);
}
