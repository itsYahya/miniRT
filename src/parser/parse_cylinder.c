#include "parser_.h"
#include "algebra.h"
#include "color.h"

void	parseCylinder(char **tokens, t__data *data)
{
	if (ft_arr_size(tokens) != 6)
		invalid_argements("cylinder");
	t_tuple orientation = get_orientation_vect3(tokens[2]);
	double diameter = ft_stod(tokens[3]);
	double height = ft_stod(tokens[4]);

	t_object* object = malloc(sizeof(t_object));
	object->position = get_position_point(tokens[1]);
	object->color.raw = get_color(tokens[5]);
	object->type = E_CYLINDER;
	object->cy.min_y = -height / 2;
	object->cy.max_y = height / 2;
	set_transform(object, transforms(2,
		orientation_transform(object->position, orientation),
		scale(diameter, 1, diameter)
	));
	ft_lstadd_back(&data->objects, ft_lstnew(object));
	if (errno)
	{
		ft_arr_free(tokens);
		ft_lstclear(&data->objects, free);
		invalid_argements("cylinder");
	}
}
