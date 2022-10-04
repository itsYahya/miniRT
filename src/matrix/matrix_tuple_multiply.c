/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_tuple_multiply.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:54:57 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/10/03 15:55:26 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_tuple	matrix_tuple_multiply(t_matrix mt, t_tuple t)
{
	return (
		(t_tuple){{
			dot(get_row(mt, 0), t),
			dot(get_row(mt, 1), t),
			dot(get_row(mt, 2), t),
			dot(get_row(mt, 3), t)
		}});
}
