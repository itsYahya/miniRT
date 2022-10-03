/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation_transform.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:18:52 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/10/03 16:21:45 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_.h"

static double	ft_xangle(t_tuple orientation)
{
	return (-atan2(orientation.z, orientation.y));
}

static double	ft_zangle(t_tuple orientation, double x_angle)
{
	orientation = matrix_tuple_multiply(rotate_x(x_angle), orientation);
	return (atan2(orientation.x, orientation.y));
}

t_matrix	orientation_transform(t_tuple coords, t_tuple orientation)
{
	double		z_angle;
	double		x_angle;
	t_matrix	rotation;

	x_angle = ft_xangle(orientation);
	z_angle = ft_zangle(orientation, x_angle);
	rotation = transforms(2,
			rotate_z(z_angle),
			rotate_x(x_angle));
	return (
		matrix_multiply(translate(coords.x, coords.y, coords.z),
			inverse(rotation)));
}
