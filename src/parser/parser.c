#include "parser_.h"

static t_type	identifier(const char	*id)
{
	if (! id)
		return (E_INVALID);
	if (ft_strcmp("A", id) == 0)
		return (E_AMBLIGHTNING);
	if (ft_strcmp("C", id) == 0)
		return (E_CAMERA);
	if (ft_strcmp("L", id) == 0)
		return (E_LIGHT);
	if (ft_strcmp("pl", id) == 0)
		return (E_PLANE);
	if (ft_strcmp("sp", id) == 0)
		return (E_SPHERE);
	if (ft_strcmp("cy", id) == 0)
		return (E_CYLINDER);
	if (ft_strcmp("cn", id) == 0)
		return (E_CONE);
	if (ft_strcmp("\n", id) == 0 || ft_strcmp("#", id) == 0)
		return (E_NEWLINE);
	return (E_INVALID);
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
	else if (id == E_CYLINDER)
		parseCylinder(tokens, data);
	else if (id == E_CONE)
		parseCone(tokens, data);
}

static int	ft_read(int fd, t__data *data)
{
	char	*line;
	char	**tokens;
	t_type	id;

	while (errno == 0)
	{
		id = E_INVALID;
		line = ft_getline(fd);
		if (ft_strlen(line) > 1)
			chomp(line, '\n');
		tokens = ft_split(line, ' ');
		line = ft_free(line);
		if (! tokens)
			break ;
		id = identifier(tokens[0]);
		if (id == E_INVALID)
			invalid_identifier(tokens[0]);
		else if (id != E_NEWLINE && id != E_INVALID)
			parseElements(tokens, id, data);
		tokens = ft_arr_free(tokens);
	}
	return (0);
}

int	parser(char *path, t__data *data)
{
	int	fd;

	if (validatePath(path))
		return (invalid_file(), 1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (invalid_file(), 1);
	ft_read(fd, data);
	return (0);
}
