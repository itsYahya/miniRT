#include "parser_.h"
#include <errno.h>
#include "raytracer.h"

static void	init(t__data *data)
{
	errno = 0;
	data->objects = NULL;
	data->lights = NULL;
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
}
