/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_row.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:51:53 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/10/03 15:52:18 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_tuple	get_row(t_matrix t, uint8_t row)
{
	if (row > 3)
		return ((t_tuple){{0, 0, 0, 0}});
	return (
		(t_tuple){{
			t.raw[row][0],
		t.raw[row][1],
			t.raw[row][2],
			t.raw[row][3]
		}});
}
