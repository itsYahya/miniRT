#ifndef MATRIX_H
# define MATRIX_H

# include <stdbool.h>
# include "tuple.h"
# include <stdint.h>

# define IDENTITY_MATRIX (t_matrix){{ \
	1, 0, 0, 0, \
	0, 1, 0, 0, \
	0, 0, 1, 0, \
	0, 0, 0, 1  \
}}

typedef union u_matrix t_matrix;
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
	float raw[4][4];
};

t_tuple		get_col(t_matrix t, uint8_t col);
t_tuple		get_row(t_matrix t, uint8_t row);
t_matrix	matrix_multiply(t_matrix mt1, t_matrix mt2);
void		print_matrix(t_matrix mt);
t_tuple		matrix_tuple_multiply(t_matrix mt, t_tuple t);
t_matrix	ft_transpose(t_matrix mt);


// typedef union u_matrix2x2 t_matrix2x2;
// union u_matrix2x2
// {
// 	struct
// 	{
// 		float	r0_c0;
// 		float	r0_c1;
// 		float	r1_c0;
// 		float	r1_c1;
// 	};
// 	float raw[2][2];
// };

// typedef union u_matrix3x3 t_matrix3x3;
// union u_matrix3x3
// {
// 	struct
// 	{
// 		float	r0_c0;
// 		float	r0_c1;
// 		float	r0_c2;

// 		float	r1_c0;
// 		float	r1_c1;
// 		float	r1_c2;

// 		float	r2_c0;
// 		float	r2_c1;
// 		float	r2_c2;
// 	};
// 	float raw[2][2];
// };

#endif
