#include "parser_.h"

static void	print_error()
{
	errno = 1;
	printf("Ratio parser: invalid input\n");
}

float	get_ratio(const char *token)
{
	float	ratio;

	ratio = ft_stod(token);
	if (ratio > 1 || ratio < 0)
		print_error();
	return (ratio);
}
