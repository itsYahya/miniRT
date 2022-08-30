#include "get_next_line.h"
#include "mutils.h"
#include "parser.h"
#include <fcntl.h>

int	ft_read(int fd)
{
	char	*line;
	
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	return (0);
}

int	parser(char *path)
{
	int	fd;
	
	if (validatePath(path))
		return (ft_putstr_fd("the file scene isn't in the right form\n", 2), 1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (1);
	ft_read(fd);
	return (0);
}