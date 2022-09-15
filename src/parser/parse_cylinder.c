#include "parser_.h"

void	parseCylinder(char **tokens, t__data *data)
{
	if (ft_arr_size(tokens) != 6)
		invalid_argements("cylinder");
	t_object* object = malloc(sizeof(t_object));
	object->position = get_position_point(tokens[1]);
	object->color = get_color(tokens[5]);
	object->type = E_CYLINDER;
	object->cy.orientation = get_orientation_vect3(tokens[2]);
	object->cy.diameter = ft_stod(tokens[3]);
	object->cy.height = ft_stod(tokens[4]);
	ft_lstadd_back(&data->objects, ft_lstnew(object));
	if (errno)
	{
		ft_arr_free(tokens);
		ft_lstclear(&data->objects, free);
		invalid_argements("cylinder");
	}
}
