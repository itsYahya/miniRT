#include "miniRT.h"
#include "get_next_line.h"
#include "mutils.h"
#include <fcntl.h>
#include "parser.h"

int	main(int argc, char **argv)
{
	t__data	data;

	if (argc != 2)
		return (ft_putstr_fd("invalid argumanet\n", 2), 1);
	parser(argv[1], &data);
	printf("camera parser: ---------------------\n");
	printf("coordinates x: %d\n", data.camera.coordinates.x);
	printf("coordinates y: %d\n", data.camera.coordinates.y);
	printf("coordinates z: %d\n", data.camera.coordinates.z);
	printf("---\n");
	printf("orientation x: %d\n", data.camera.orientation_vect.x);
	printf("orientation y: %d\n", data.camera.orientation_vect.y);
	printf("orientation z: %d\n", data.camera.orientation_vect.z);
	printf("---\n");
	printf("fov: %d\n", data.camera.fov);
	return (0);
}
