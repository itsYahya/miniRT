#include "tuple.h"

t_tuple	tuple_product(t_tuple t1, t_tuple t2)
{
	return ((t_tuple){{
		t1.x * t2.x,
		t1.y * t2.y,
		t1.z * t2.z,
		t1.w * t2.w
	}});
}
