#include "parser_.h"

void	parsePlane(char **tokens, t__data *data)
{
	if (ft_arr_size(tokens) != 4)
		invalid_argements("plane");
	t_uobject* object = malloc(sizeof(t_uobject));
	object->plane.point = get_vect3(tokens[1]);
	object->plane.vect = get_orientation_vect3(tokens[2]);
	object->plane.color = get_color(tokens[3]);
	ft_lstadd_back(&data->objects, ft_lstnew(object, E_PLANE));
	if (errno)
	{
		ft_arr_free(tokens);
		ft_lstclear(&data->objects, free);
		invalid_argements("plane");
	}
}
