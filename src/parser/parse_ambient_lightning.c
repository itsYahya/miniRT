#include "parser_.h"

int	parseAmbLightning(char **tokens, t__data *data)
{
	static int	count = 0;

	if (count++)
		return (multiple_elm("A"), 0);
	if (ft_arr_size(tokens) != 3)
		return (invalid_argements("Ambient lightning"), 0);
	data->ambient.ratio = get_ratio(tokens[1]);
	data->ambient.color.raw = get_color(tokens[2]);
	if (errno)
		invalid_argements("Ambient lightning");
	return (0);
}
