#include "parser_.h"

void	parseLight(char **tokens, t__data *data)
{
	if (ft_arr_size(tokens) != 4)
		invalid_argements("light");
	t_light	*light = (t_light *)malloc(sizeof(t_light));
	light->point = get_position_point(tokens[1]);
	light->bRatio = get_ratio(tokens[2]);
	light->color = get_color(tokens[3]);
	ft_lstadd_back(&data->lights, ft_lstnew(light));
	if (errno)
	{
		ft_lstclear(&data->objects, free);
		invalid_argements("light");
	}
}
