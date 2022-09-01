#include "mutils.h"
#include "parser.h"
#include "miniRT.h"
#include <stdio.h>

static void	print_error_exit()
{
	printf("Ratio parser: invalid input\n");
	exit(1);
}

float	get_ratio(const char *token)
{
	float	ratio;

	ratio = ft_stod(token);
	if (ratio > 1 || ratio < 0)
		print_error_exit();
	return (ratio);
}