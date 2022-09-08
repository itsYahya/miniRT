#include "matrix.h"

t_matrix	ft_transpose(t_matrix mt)
{
	t_matrix	result;
	int			i;
	int			j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			result.raw[j][i] = mt.raw[i][j];
	}
	return (result);
}
