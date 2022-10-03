/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:28:11 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/10/03 16:41:41 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_.h"

int	parse_light(char **tokens, t__data *data)
{
	t_light	*light;

	if (ft_arr_size(tokens) != 4)
		return (invalid_argements("light"), 0);
	light = (t_light *)malloc(sizeof(t_light));
	light->point = get_position_point(tokens[1]);
	light->bratio = get_ratio(tokens[2]);
	light->color = to_color(get_color(tokens[3]));
	ft_lstadd_back(&data->lights, ft_lstnew(light));
	if (errno)
		invalid_argements("light");
	return (0);
}
