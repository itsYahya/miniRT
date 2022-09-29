#include "parser_.h"
#include "raytracer.h"
#include "miniRT.h"
#include <signal.h>
#include "h_threads.h"


int	main(int argc, char **argv)
{
	t__data	data;

	init(&data);
	if (argc != 2)
		return (1);
	parser(argv[1], &data);
	ft_canvas(&data.canvas, WIDTH, HEIGHT);
	if (errno == 0)
		ft_threads_lunsher(&data);
	ft_destroy(&data);
}
