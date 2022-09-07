#include "matrix.h"

t_tuple	get_col(t_matrix t, uint8_t col)
{
	if (col > 3)
		return (t_tuple){0, 0, 0, 0};
	return (t_tuple){
		t.raw[0][col],
		t.raw[1][col],
		t.raw[2][col],
		t.raw[3][col]
	};
}
