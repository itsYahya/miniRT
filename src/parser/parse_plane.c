#include "parser_.h"

int	parsePlane(char **tokens, t__data *data)
{
	t_object	*object;
	int			size;

	size = ft_arr_size(tokens);
	if (size < 4 || size > 7)
		return (invalid_argements("plane"), 0);
	object = malloc(sizeof(t_object));
	if (!object)
		return (errno = 1, 0);
	object->position = get_position_point(tokens[1]);
	object->type = E_PLANE;
	object->plane.orientation = get_orientation_vect3(tokens[2]);
	ft_set_material(object, tokens, 4, to_color(get_color(tokens[3])));
	ft_lstadd_back(&data->objects, ft_lstnew(object));
	if (errno)
		invalid_argements("plane");
	return (0);
}
