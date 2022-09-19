#include "tuple.h"

/**
 * the smaller the dot product, the larger the angle between the vectors
 * 1  means  the  vectors  are identical
 * -1 means they point in opposite directions
 **/
double	dot(t_tuple v1, t_tuple v2)
{
	return (
		v1.x * v2.x
	 	+ v1.y * v2.y
	 	+ v1.z * v2.z
	 	+ v1.w * v2.w
	);
}
