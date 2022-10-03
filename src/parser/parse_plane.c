/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:29:02 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/10/03 16:29:03 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_.h"

int	parse_plane(char **tokens, t__data *data)
{
	t_object	*object;
	int			size;

	size = ft_arr_size(tokens);
	if (size < 4 || size > 7)
		return (invalid_argements("plane"), 0);
	object = malloc(sizeof(t_object));
	if (!object)
		return (errno = 1, 0);
	object->position = get_position_point(tokens[1]);
	object->type = E_PLANE;
	object->plane.orientation = get_orientation_vect3(tokens[2]);
	ft_set_material(object, tokens, 4, to_color(get_color(tokens[3])));
	ft_lstadd_back(&data->objects, ft_lstnew(object));
	if (errno)
		invalid_argements("plane");
	return (0);
}
