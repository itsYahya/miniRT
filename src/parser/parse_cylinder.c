#include "parser_.h"
#include "algebra.h"

float	rad2deg(float x)
{
	return (x * 180) / M_PI;
}

float	get_angle(t_tuple projection_vect)
{
	float angle = EPSILON;
	if (! is_equal(projection_vect, vector(0, 0, 0)))
		angle = acos(dot(projection_vect, vector(0, 0, 1)));
	if (! equal(angle, 0))
		angle = SIGN(angle);
	return (angle);
}

static void	set_cy_transform(t_object *object)
{
	t_matrix	transform;
	float		x_angle;
	float		y_angle;

	x_angle = get_angle(clone_withx(object->cy.orientation, 0.0f));
	y_angle = get_angle(clone_withy(object->cy.orientation, 0.0f));
	printf("x_angle: %f\n", x_angle);
	printf("y_angle: %f\n", y_angle);
	transform = IDENTITY_MATRIX;
	// transform = matrix_multiply(transform, translate(object->position.x, object->position.y, object->position.z));
	transform = matrix_multiply(transform, rotate_x(x_angle));
	transform = matrix_multiply(transform, rotate_y(y_angle));
	// transform = matrix_multiply(transform, scale(object->cy.diameter, object->cy.diameter, object->cy.height / 2.0f));
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
