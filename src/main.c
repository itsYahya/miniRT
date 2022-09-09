#include "get_next_line.h"
#include "mutils.h"
#include <fcntl.h>
#include "matrix.h"
#include <errno.h>
#include "transform.h"
#include "canvas.h"
#include "raytracer.h"
#include "algebra.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int		i;
	(void)	i;

	t_material	m = ft_material();
	t_tuple position = point(0, 0, 0);

	// t_tuple	eyev = vector(0, sqrt(2) / 2, -sqrt(2) / 2);
	t_tuple	eyev = vector(0, 0, -1);
	t_tuple	normalv = vector(0, 0, -1);
	t_light light = point_light(point(0, 10, -10), ft_color(1, 1, 1));

	t_color	result = ft_lighting(m, light, position, eyev, normalv);
	print_color(result);
}
