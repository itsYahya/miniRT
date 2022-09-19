// #include "_parser.h"
// #include "algebra.h"
// #include "color.h"

// double	rad2deg(double x)
// {
// 	return (x * 180) / acos(-1);
// }

// static double	get_xangle(t_tuple orientationv)
// {
// 	double	angle;
// 	t_tuple	projection_vect;

// 	projection_vect = clone_withx(orientationv, 0.0);
// 	if (! equal(projection_vect.z, 0.0)) {
// 		projection_vect = clone_withx(orientationv, 0.0);
// 		angle = angle_between(vector(0, 0, 1), projection_vect);
// 		if (projection_vect.y > 0)
// 			angle *= -1;
// 	} else {
// 		angle = angle_between(vector(1, 0, 0), orientationv);
// 		printf("orientation.x: %f\n", orientationv.x);
// 		if (orientationv.x < 0)
// 			angle = acos(-1) - angle;
// 		if (orientationv.y > 0)
// 			angle = -angle;
// 	}
// 	return (angle);
// }

// static double	get_yangle(t_tuple orientationv)
// {
// 	double	angle;
// 	t_tuple	projection_vect;

// 	projection_vect = clone_withy(orientationv, 0.0);
// 	angle = angle_between(vector(0, 0, 1), projection_vect);
// 	if (projection_vect.x < 0)
// 		angle *= -1;
// 	return (angle);
// }

// static void	set_cy_transform(t_object *object)
// {
// 	double		x_angle;
// 	double		y_angle;

// 	x_angle = get_xangle(object->cy.orientation);
// 	y_angle = get_yangle(object->cy.orientation);
// 	printf("x_angle: %f\n", rad2deg(x_angle));
// 	printf("y_angle: %f\n", rad2deg(y_angle));

// 	object->transform = transforms(4,
// 		translate(object->position.x, object->position.y, object->position.z),
// 		rotate_y(y_angle),
// 		rotate_x(-x_angle),
// 		scale(object->cy.diameter, object->cy.diameter, object->cy.height / 2.0)
// 	);
// }

// void	parse_cylinder(char **tokens, t_pdata *data)
// {
// 	if (ft_arr_size(tokens) != 6)
// 		invalid_argements("cylinder");
// 	t_object* object = malloc(sizeof(t_object));
// 	object->position = get_position_point(tokens[1]);
// 	object->color.raw = get_color(tokens[5]);
// 	object->type = E_CYLINDER;
// 	object->cy.orientation = get_orientation_vect3(tokens[2]);
// 	object->cy.diameter = ft_stod(tokens[3]);
// 	object->cy.height = ft_stod(tokens[4]);
// 	set_cy_transform(object);
// 	ft_lstadd_back(&data->objects, ft_lstnew(object));
// 	if (errno)
// 	{
// 		ft_arr_free(tokens);
// 		ft_lstclear(&data->objects, free);
// 		invalid_argements("cylinder");
// 	}
// }
