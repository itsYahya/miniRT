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
	(void)argc;
	(void)argv;
	renderer();
}
