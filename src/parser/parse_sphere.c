/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:29:41 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/10/03 17:15:55 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_.h"

void	ft_set_material(t_object *object,
		char **tokens, int index, t_color color)
{
	object->material.color = color;
	object->material.ambient = 0.1;
	object->material.diffuse = 0.9;
	object->material.specular = 0.9;
	object->material.shininess = 200.0;
	if (tokens[index] == NULL)
		return ;
	object->material.diffuse = ft_stod(tokens[index++]);
	if (tokens[index] == NULL)
		return ;
	object->material.specular = ft_stod(tokens[index++]);
	if (tokens[index] == NULL)
		return ;
	object->material.shininess = ft_stod(tokens[index++]);
}

int	parse_sphere(char **tokens, t__data *data)
{
	int			size;
	t_object	*object;

	size = ft_arr_size(tokens);
	if (size < 4 || size > 7)
		return (invalid_argements("sphere"), 0);
	object = malloc(sizeof(t_object));
	if (!object)
		return (*ft_errno() = 1, 0);
	object->position = get_position_point(tokens[1]);
	object->type = E_SPHERE;
	object->sphere.diameter = ft_stod(tokens[2]);
	ft_set_material(object, tokens, 4, to_color(get_color(tokens[3])));
	ft_lstadd_back(&data->objects, ft_lstnew(object));
	if (*ft_errno())
		invalid_argements("sphere");
	return (0);
}
