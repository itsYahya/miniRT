#include "miniRT.h"
#include "get_next_line.h"
#include "mutils.h"
#include <fcntl.h>
#include "parser.h"

int	main(int argc, char **argv)
{
	
	if (argc != 2)
		return (ft_putstr_fd("invalid argumanet\n", 2), 1);
	parser(argv[1]);
	return (0);
}
