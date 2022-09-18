#include "raytracer.h"

t_inter	ft_inter(float t, t_object object)
{
	return (t_inter){t, object};
}

t_xs	ft_inters(unsigned int count, ...)
{
	va_list			ap;
	t_inter	*arr;
	unsigned int	i;

	va_start(ap, count);
	arr = (t_inter *)malloc(sizeof(t_inter) * count);
	if (! arr)
		return ((t_xs){-1, NULL});
	i = -1;
	while (++i < count)
		arr[i] = va_arg(ap, t_inter);
	va_end(ap);
	return ((t_xs){count, arr});
}

void	destroy_inters(t_xs	*xs)
{
	if (! xs)
		return ;
	xs->inters = ft_free(xs->inters);
	xs->count = -1;
}
