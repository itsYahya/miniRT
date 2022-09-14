#include "utils.h"

void	arr_print(char **arr)
{
	while (arr && *arr)
		printf("%s ", *arr++);
	printf("\n");
}
