#include "get_next_line.h"
#include "mutils.h"
#include <fcntl.h>
#include "matrix.h"
#include <errno.h>
#include "transform.h"
#include "canvas.h"
#include "raytracer.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int		i;

	t_object s = ft_sphere();
	t_intersection i1 = ft_intersection(10, s);
	t_intersection i2 = ft_intersection(2, s);
	t_xs xs = ft_intersections(2, i1, i2);
	printf("count: %d\n", xs.count);
	i = -1;
	while (++i < xs.count)
		printf("%f\n", xs.inters[i].t);
	destroy_intersections(&xs);
}
