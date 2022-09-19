#include "_parser.h"

static void	print_error_exit()
{
	errno = 1;
	printf("Ratio parser: invalid input\n");
}

double	get_ratio(const char *token)
{
	double	ratio;

	ratio = ft_stod(token);
	if (ratio > 1 || ratio < 0)
		print_error_exit();
	return (ratio);
}
