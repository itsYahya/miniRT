/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:26:57 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/10/03 16:27:13 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_.h"
#include "algebra.h"
#include "color.h"

static t_object	*ft_init_cylinder(char **tokens)
{
	t_object	*object;
	t_tuple		orientation;
	double		diameter;
	double		height;

	orientation = get_orientation_vect3(tokens[2]);
	diameter = ft_stod(tokens[3]);
	height = ft_stod(tokens[4]);
	object = malloc(sizeof(t_object));
	if (!object)
		return (errno = 1, NULL);
	ft_set_material(object, tokens, 6, to_color(get_color(tokens[5])));
	object->position = get_position_point(tokens[1]);
	object->type = E_CYLINDER;
	object->cy.min_y = -height / 2;
	object->cy.max_y = height / 2;
	set_transform(object, transforms(2,
			orientation_transform(object->position, orientation),
			scale(diameter, 1, diameter)));
	return (object);
}

int	parse_cylinder(char **tokens, t__data *data)
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
