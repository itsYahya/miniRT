#include "miniRT.h"
#include "get_next_line.h"
#include "mutils.h"
#include <fcntl.h>
#include "parser.h"
#include "matrix.h"
#include <errno.h>
#include "transform.h"
#include "canvas.h"

int	main(int argc, char **argv)
{
	t__data	data;

	errno = 0;
	if (argc != 2 || parser(argv[1], &data))
		return (1);
	renderer_rt(&data);
}
