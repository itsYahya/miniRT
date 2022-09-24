#include "parser_.h"
#include "algebra.h"
#include "color.h"

static t_object	*ft_init_cylinder(char **tokens)
{
	t_object	*object;

	object = malloc(sizeof(t_object));
	if (!object)
		return (errno = 1, NULL);
	object->position = get_position_point(tokens[1]);
	object->color.raw = get_color(tokens[5]);
	object->type = E_CYLINDER;
	object->cy.orientation = get_orientation_vect3(tokens[2]);
	object->cy.diameter = ft_stod(tokens[3]);
	object->cy.height = ft_stod(tokens[4]);
	object->cy.min_y = -object->cy.height / 2;
	object->cy.max_y = object->cy.height / 2;
	set_transform(object, orientation_transform(object->position, object->cy.orientation));
	ft_set_material(object, tokens, 6);
	return (object);
}

int	parseCylinder(char **tokens, t__data *data)
{
	t_object	*object;
	int			size;

	size = ft_arr_size(tokens);
	if (size < 6 || size > 9)
		return (invalid_argements("cylinder"), 0);
	object = ft_init_cylinder(tokens);
	ft_lstadd_back(&data->objects, ft_lstnew(object));
	if (errno)
		invalid_argements("cylinder");
	return (0);
}
