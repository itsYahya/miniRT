#include "parser_.h"

void	parseSphere(char **tokens, t__data *data)
{
	if (ft_arr_size(tokens) != 4)
		invalid_argements("sphere");
	t_uobject* object = malloc(sizeof(t_uobject));
	object->sphere.center = get_vect3(tokens[1]);
	object->sphere.diameter = ft_stod(tokens[2]);
	object->sphere.color = get_color(tokens[3]);
	ft_lstadd_back(&data->objects, ft_lstnew(object, E_SPHERE));
	if (errno)
	{
		ft_arr_free(tokens);
		ft_lstclear(&data->objects, free);
		invalid_argements("sphere");
	}
}
