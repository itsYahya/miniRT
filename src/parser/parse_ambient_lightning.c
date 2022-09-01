#include "parser.h"
#include "mutils.h"
#include <stdio.h>

void	parseAmbLightning(char **tokens, t__data *data)
{
	static int	count = 0;

	if (count++)
		multiple_elm_exit("A");
	if (ft_arr_size(tokens) != 3)
		invalid_argements("Ambient lightning");
	data->ambient.ratio = get_ratio(tokens[1]);
	data->ambient.color = get_color(tokens[2]);
}