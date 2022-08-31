#include "get_next_line.h"
#include "mutils.h"
#include "parser.h"
#include <fcntl.h>
#include <stdio.h>
#include "sceneMaterial.h"

static int	identifier(char	*id)
{
	if (ft_strncmp(id, "A", 1) == 0)
		return ('A');
	if (ft_strncmp(id, "C", 1) == 0)
		return ('C');
	if (ft_strncmp(id, "L", 1) == 0)
		return ('L');
	if (ft_strncmp("pl", id, 2) == 0)
		return ('P');
	if (ft_strncmp("sp", id, 2) == 0)
		return ('S');
	if (ft_strncmp("cy", id, 2) == 0)
		return ('Y');
	if (ft_strncmp("\n", id, 1) == 0 )
		return ('N');
	return (-1);
}

static void	parseElements(char **tokens, int id, t__data *data)
{
	if (id == ambLightning)
		parseAmbLightning(tokens, data);
	else if (id == camera)
		parseCamera(tokens, data);
	else if (id == light)
		parseLight(tokens, data);
	else if (id == sphere)
		parseSphere(tokens, data);
	else if (id == plane)
		parsePlane(tokens, data);
	else
		parseCylinder(tokens, data);
}

static int	ft_read(int fd, t__data *data)
{
	char	*line;
	char	**tokens;
	int		id;

	line = get_next_line(fd);
	while (line)
	{
		tokens = ft_split(line, ' ');
		id = identifier(tokens[0]);
		if (id < 0)
			exit(1);
		if (id != 'N')
			parseElements(tokens, id, data);
		line = get_next_line(fd);
	}
	return (0);
}

int	parser(char *path, t__data *data)
{
	int	fd;

	if (validatePath(path))
		return (ft_putstr_fd("the file scene isn't in the right form\n", 2), 1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (1);
	ft_read(fd, data);
	return (0);
}
