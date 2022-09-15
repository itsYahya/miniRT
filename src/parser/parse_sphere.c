#include "parser_.h"

void	parseSphere(char **tokens, t__data *data)
{
	if (ft_arr_size(tokens) != 4)
		invalid_argements("sphere");
	t_object* object = malloc(sizeof(t_object));
	object->position = get_position_point(tokens[1]);
	object->color = get_color(tokens[3]);
	object->type = E_SPHERE;
	object->sphere.diameter = ft_stod(tokens[2]);
	ft_lstadd_back(&data->objects, ft_lstnew(object));
	if (errno)
	{
		ft_arr_free(tokens);
		ft_lstclear(&data->objects, free);
		invalid_argements("sphere");
	}
}
