/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:25:52 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/10/03 17:15:55 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_.h"
#include "algebra.h"
#include "color.h"

t_object	new_cone(t_tuple coords, t_tuple orientation,
	t_fpair radius_height, t_color color)
{
	t_object	object;
	double		radius;
	double		height;
	t_matrix	transform;

	radius = radius_height._0;
	height = radius_height._1;
	object.material.color = color;
	object.type = E_CONE;
	object.cn.min_y = -1;
	object.cn.max_y = 1;
	transform = transforms(2,
			orientation_transform(coords, orientation),
			scale(radius, height / 2, radius));
	set_transform(&object, transform);
	return (object);
}

int	parse_cone(char **tokens, t__data *data)
{
	t_object	*object;

	if (ft_arr_size(tokens) != 6)
		return (invalid_argements("cone"), 0);
	object = malloc(sizeof(t_object));
	*object = new_cone(get_position_point(tokens[1]),
			get_orientation_vect3(tokens[2]),
			(t_fpair){{ft_stod(tokens[3]), ft_stod(tokens[4])}},
			to_color(get_color(tokens[5])));
	ft_set_material(object, tokens, 6, to_color(get_color(tokens[5])));
	ft_lstadd_back(&data->objects, ft_lstnew(object));
	if (*ft_errno())
		invalid_argements("cylinder");
	return (0);
}
