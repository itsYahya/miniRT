#include "parser_.h"

void	parseLight(char **tokens, t__data *data)
{
	if (ft_arr_size(tokens) != 4)
		invalid_argements("light");
	data->light.point = get_position_point(tokens[1]);
	data->light.bRatio = get_ratio(tokens[2]);
	data->light.color = get_color(tokens[3]);
	if (errno)
	{
		ft_lstclear(&data->objects, free);
		invalid_argements("light");
	}
}
