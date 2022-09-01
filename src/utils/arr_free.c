#include "mutils.h"

void	*ft_arr_free(char **arr)
{
	int	i;

	i = -1;
	while (arr && arr[++i])
		arr[i] = ft_free(arr[i]);
	arr = ft_free(arr);
	return (NULL);
}
