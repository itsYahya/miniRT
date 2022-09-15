#include "parser_.h"
#include <errno.h>
#include "raytracer.h"

static void	init(t__data *data)
{
	errno = 0;
	data->objects = NULL;
}

int	main(int argc, char **argv)
{
	t__data	data;

	init(&data);
	if (argc != 2 || parser(argv[1], &data))
		return (1);
	if (! data.objects)
		printf("no object");
	render(&data);
	// t_ray	r = (t_ray){point(0, 0, 0), vector(0, 1, 0)};
	// uint32_t color = cylinder_intersect(ft_cylinder(), r);
	// printf("%x\n", color);
}
