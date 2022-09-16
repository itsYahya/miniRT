#include "matrix.h"

t_matrix	transforms(int count, ...)
{
	int		i;
	va_list	ap;
	t_matrix	transform;

	va_start(ap, count);
	i = -1;
	transform = IDENTITY_MATRIX;
	while (++i < count)
		transform = matrix_multiply(transform, va_arg(ap, t_matrix));
	return (transform);
}
