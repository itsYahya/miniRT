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
	if (parser(argv[1], &data) != 0)
		exit(1);
	printf("camera parser: ---------------------\n");
	printf("coordinates x: %f\n", data.camera.coordinates.x);
	printf("coordinates y: %f\n", data.camera.coordinates.y);
	printf("coordinates z: %f\n", data.camera.coordinates.z);
	printf("---\n");
	printf("orientation x: %f\n", data.camera.orientation_vect.x);
	printf("orientation y: %f\n", data.camera.orientation_vect.y);
	printf("orientation z: %f\n", data.camera.orientation_vect.z);
	printf("---\n");
	printf("fov: %f\n", data.camera.fov);
	return (0);
}
