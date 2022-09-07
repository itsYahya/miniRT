#include "matrix.h"

t_tuple		matrix_tuple_multiply(t_matrix mt, t_tuple t)
{
	return (t_tuple){
		dot(get_row(mt, 0), t),
		dot(get_row(mt, 1), t),
		dot(get_row(mt, 2), t),
		dot(get_row(mt, 3), t)
	};
}
