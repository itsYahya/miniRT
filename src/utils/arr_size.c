#include "utils.h"

int	ft_arr_size(char **arr)
{
	int	size;

	size = 0;
	while (arr && *(arr++) && ++size)
		;
	return (size);
}
