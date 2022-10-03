/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:24:15 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/10/03 17:15:55 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "parser_.h"

static double	get_fov(const char *arg)
{
	double	result;

	result = ft_stod(arg);
	if (result < 0 || result > 180)
		*ft_errno() = 1;
	return (result);
}

int	parse_camera(char **tokens, t__data *data)
{
	static int	count = 0;

	if (count++)
		return (multiple_elm("C"), 0);
	if (ft_arr_size(tokens) != 4)
		return (invalid_argements("camera"), 0);
	data->camera.coordinates = get_position_point(tokens[1]);
	data->camera.orientation_vect = get_orientation_vect3(tokens[2]);
	data->camera.fov = get_fov(tokens[3]);
	if (*ft_errno())
		invalid_argements("camera");
	return (0);
}
