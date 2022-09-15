#include "parser_.h"

static void	set_cy_transform(t_object *object)
{
	t_matrix	transform;

	transform = IDENTITY_MATRIX;
	transform = matrix_multiply(transform, translate(object->position.x, object->position.y, object->position.z));
	// TODO: fix rotation to match orientation vector
	transform = matrix_multiply(transform, rotate_x(object->cy.orientation.x * M_2_PI));
	transform = matrix_multiply(transform, rotate_y(object->cy.orientation.y * M_2_PI));
	transform = matrix_multiply(transform, rotate_z(object->cy.orientation.z * M_2_PI));
	transform = matrix_multiply(transform, scale(1, 1, object->cy.height / 2.0f));
	object->transform = transform;
}

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
	set_cy_transform(object);
	ft_lstadd_back(&data->objects, ft_lstnew(object));
	if (errno)
	{
		ft_arr_free(tokens);
		ft_lstclear(&data->objects, free);
		invalid_argements("cylinder");
	}
}
