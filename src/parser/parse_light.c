#include "parser_.h"

int	parseLight(char **tokens, t__data *data)
{
	if (ft_arr_size(tokens) != 4)
		return (invalid_argements("light"), 0);
	t_light	*light = (t_light *)malloc(sizeof(t_light));
	light->point = get_position_point(tokens[1]);
	light->bratio = get_ratio(tokens[2]);
	light->color = to_color(get_color(tokens[3]));
	ft_lstadd_back(&data->lights, ft_lstnew(light));
	if (errno)
		invalid_argements("light");
	return (0);
}
