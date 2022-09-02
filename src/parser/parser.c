#include "get_next_line.h"
#include "mutils.h"
#include "parser.h"
#include <fcntl.h>
#include <stdio.h>
#include "objects.h"

static int	identifier(const char	*id)
{
	if (ft_strcmp("A", id) == 0)
		return ('A');
	if (ft_strcmp("C", id) == 0)
		return ('C');
	if (ft_strcmp("L", id) == 0)
		return ('L');
	if (ft_strcmp("pl", id) == 0)
		return ('P');
	if (ft_strcmp("sp", id) == 0)
		return ('S');
	if (ft_strcmp("cy", id) == 0)
		return ('Y');
	if (ft_strcmp("\n", id) == 0)
		return ('N');
	return (-1);
}

static void	parseElements(char **tokens, int id, t__data *data)
{
	if (id == E_AMBLIGHTNING)
		parseAmbLightning(tokens, data);
	else if (id == E_CAMERA)
		parseCamera(tokens, data);
	else if (id == E_LIGHT)
		parseLight(tokens, data);
	else if (id == E_SPHERE)
		parseSphere(tokens, data);
	else if (id == E_PLANE)
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
		if (ft_strlen(line) > 1)
			chomp(line, '\n');
		tokens = ft_split(line, ' ');
		line = ft_free(line);
		if (! tokens || !*tokens)
			return (ft_arr_free(tokens), exit(1), 0);
		id = identifier(tokens[0]);
		if (id < 0)
			invalid_identifier();
		if (id != 'N')
			parseElements(tokens, id, data);
		tokens = ft_arr_free(tokens);
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
