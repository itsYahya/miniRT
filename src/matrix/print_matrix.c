#include "matrix.h"

void		print_matrix(t_matrix mt)
{
	int i = -1;
	int	j = -1;

	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			printf("%f  ", mt.raw[i][j]);
		printf("\n");
	}
}
