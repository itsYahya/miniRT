#include "parser_.h"

void	parsePlane(char **tokens, t__data *data)
{
	t_object	*object;
	int			size;

	size = ft_arr_size(tokens);
	if (size < 4 || size > 7)
		invalid_argements("plane");
	object = malloc(sizeof(t_object));
	if (!object)
		exit(0);
	object->position = get_position_point(tokens[1]);
	object->color.raw = get_color(tokens[3]);
	object->type = E_PLANE;
	object->plane.orientation = get_orientation_vect3(tokens[2]);
	ft_set_material(object, tokens, 4);
	ft_lstadd_back(&data->objects, ft_lstnew(object));
	if (errno)
	{
		ft_arr_free(tokens);
		ft_lstclear(&data->objects, free);
		invalid_argements("plane");
	}
}
