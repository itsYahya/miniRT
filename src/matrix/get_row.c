#include "matrix.h"

t_tuple	get_row(t_matrix t, uint8_t row)
{
	if (row > 3)
		return (t_tuple){{0, 0, 0, 0}};
	return (t_tuple){{
		t.raw[row][0],
		t.raw[row][1],
		t.raw[row][2],
		t.raw[row][3]
	}};
}
