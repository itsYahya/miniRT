#include "parser_.h"

void	set_transform(t_object *obj, t_matrix transform)
{
	obj->transform = transform;
	obj->inverted_transform = inverse(transform);
	obj->transpose = ft_transpose(inverse(transform));
}
