/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:04:07 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/10/03 16:06:25 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix	translate(float x, float y, float z)
{
	return (
		(t_matrix){{
			1, 0, 0, x,
			0, 1, 0, y,
			0, 0, 1, z,
			0, 0, 0, 1
		}});
}

t_matrix	scale(float x, float y, float z)
{
	return (
		(t_matrix){{
			x, 0, 0, 0,
			0, y, 0, 0,
			0, 0, z, 0,
			0, 0, 0, 1
		}});
}

t_matrix	rotate_x(float radians)
{
	return (
		(t_matrix){{
			1, 0, 0, 0,
			0, cos(radians), -sin(radians), 0,
			0, sin(radians), cos(radians), 0,
			0, 0, 0, 1
		}});
}

t_matrix	rotate_y(float radians)
{
	return (
		(t_matrix){{
			cos(radians), 0, sin(radians), 0,
			0, 1, 0, 0,
			-sin(radians), 0, cos(radians), 0,
			0, 0, 0, 1
		}});
}

t_matrix	rotate_z(float radians)
{
	return (
		(t_matrix){{
			cos(radians), -sin(radians), 0, 0,
			sin(radians), cos(radians), 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		}});
}
