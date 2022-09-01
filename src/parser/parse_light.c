#include "sceneMaterial.h"
#include <stdio.h>
#include "parser.h"
#include "mutils.h"
#include <errno.h>
#include <stdio.h>

static void	print_error_exit()
{
	printf("light parser: invalid cordinates\n");
	exit(1);
}

void	parseLight(char **tokens, t__data *data)
{
	if (ft_arr_size(tokens) != 4)
		invalid_argements("light");
	data->light.point = get_vect3(tokens[1]);
	data->light.bRatio = get_ratio(tokens[2]);
	data->light.color = get_color(tokens[3]);
	if (errno)
		print_error_exit();
}
