/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_invert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:52:50 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/10/03 15:54:31 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

static float	determinant(t_matrix m, uint8_t size);

static t_matrix	submatrix(t_matrix m, uint8_t size, uint8_t row, uint16_t col)
{
	t_matrix	result;
	t_pair		result_index;
	t_pair		index;

	result_index.y = 0;
	index.y = -1;
	while (++index.y < size)
	{
		if (index.y == row)
			continue ;
		index.x = -1;
		result_index.x = -1;
		while (++index.x < size)
		{
			if (index.x == col)
				continue ;
			result.raw[result_index.y][++result_index.x]
				= m.raw[index.y][index.x];
		}
		result_index.y++;
	}
	return (result);
}

static float	cofactor(t_matrix m, uint8_t size, uint8_t row, uint8_t col)
{
	float	minor;

	m = submatrix(m, size, row, col);
	minor = determinant(m, size - 1);
	if ((row + col) % 2 == 0)
		return (minor);
	return (-minor);
}

static float	determinant(t_matrix m, uint8_t size)
{
	float	det;
	int		col;

	if (size == 2)
		return (m.r0_c0 * m.r1_c1 - m.r1_c0 * m.r0_c1);
	det = 0;
	col = -1;
	while (++col < size)
		det += m.raw[0][col] * cofactor(m, size, 0, col);
	return (det);
}

t_matrix	inverse(t_matrix mt)
{
	float		det;
	int			i;
	int			j;
	t_matrix	result;

	det = determinant(mt, 4);
	if (det == 0)
		return (mt);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			result.raw[i][j] = cofactor(mt, 4, j, i) / det;
	}
	return (result);
}
