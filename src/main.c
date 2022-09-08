#include "miniRT.h"
#include "get_next_line.h"
#include "mutils.h"
#include <fcntl.h>
#include "parser.h"
#include "matrix.h"
#include <errno.h>
#include "transform.h"
#include "canvas.h"
#include "raytracer.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	t_ray r = ray(point(2, 3, 4), vector(1, 0, 0));
	print_point(position(r, 0));
	print_point(position(r, 1));
	print_point(position(r, -1));
	print_point(position(r, 2.5));
}
