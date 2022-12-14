/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:56:45 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/10/03 17:13:29 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include <stdbool.h>
# include "tuple.h"
# include <stdint.h>
# include "algebra.h"
# include <stdio.h>
# include "pair.h"
# include <math.h>
# include <stdarg.h>

typedef union u_matrix	t_matrix;
union u_matrix
{
	struct
	{
		float	r0_c0;
		float	r0_c1;
		float	r0_c2;
		float	r0_c3;

		float	r1_c0;
		float	r1_c1;
		float	r1_c2;
		float	r1_c3;

		float	r2_c0;
		float	r2_c1;
		float	r2_c2;
		float	r2_c3;

		float	r3_c0;
		float	r3_c1;
		float	r3_c2;
		float	r3_c3;
	};
	float	raw[4][4];
};

t_tuple		get_col(t_matrix t, uint8_t col);
t_tuple		get_row(t_matrix t, uint8_t row);
t_matrix	matrix_multiply(t_matrix mt1, t_matrix mt2);
bool		matrix_equal(t_matrix mt1, t_matrix mt2);
void		print_matrix(t_matrix mt);
t_tuple		matrix_tuple_multiply(t_matrix mt, t_tuple t);
t_matrix	ft_transpose(t_matrix mt);
t_matrix	inverse(t_matrix mtx);

t_matrix	translate(float x, float y, float z);
t_matrix	scale(float x, float y, float z);
t_matrix	rotate_x(float radians);
t_matrix	rotate_y(float radians);
t_matrix	rotate_z(float radians);
t_matrix	transforms(int count, ...);

t_matrix	identity_matrix(void);

#endif
