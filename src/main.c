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

	t_ray r = ft_ray(point(0, 0, -5), vector(0, 0, 1));
	t_object	s = ft_sphere();
	set_transform(&s, rotate_x(M_PI / 2));
	t_xs xs = ft_intersect(s, r);
	printf("count: %d\n", xs.count);
	i = -1;
	while (++i < xs.count)
		printf("%f\n", xs.inters[i].t);
	destroy_intersections(&xs);
}
