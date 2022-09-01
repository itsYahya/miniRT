#include "parser.h"
#include "mutils.h"
#include <stdio.h>

void	parseAmbLightning(char **tokens, t__data *data)
{
	static int	count = 0;

	if (count)
		multiple_elm_exit("A");
	if (ft_arr_size(tokens) != 3)
		invalid_argements("Ambient lightning");
	data->ambient.ratio = get_ratio(tokens[1]);
	data->ambient.color = get_color(tokens[2]);
	printf("%f\t%d\n", data->ambient.ratio, data->ambient.color);
	printf("all goood for the ambient lightning so far\n");
}