#include "_parser.h"

static int	identifier(const char	*id)
{
	if (! id)
		return (-1);
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
	return (-1);
}

static void	parse_line(t_type id, char **tokens, t_pdata *pdata)
{
	t_camera	camera;

	if (! tokens || ! pdata)
		return ;
	if (id == E_INVALID)
		return invalid_identifier();
	if (id == E_CAMERA)
	{
		camera = parse_camera(tokens);
		if (errno == 0)
			pdata->camera = camera;
	}
	else if (id == E_LIGHT)
		add_light(&pdata->scene, parse_light(tokens));
	else if (id == E_SPHERE)
		add_object(&pdata->scene, parse_sphere(tokens));
	else if (id == E_PLANE)
		add_object(&pdata->scene, parse_plane(tokens));
	else if (id == E_CYLINDER)
		add_object(&pdata->scene, parse_cylinder(tokens));
	else if (id == E_CONE)
		add_object(&pdata->scene, parse_cone(tokens));
}

static char	**get_next_line_tokens(int fd)
{
	char	*line;
	char	**tokens;

	line = get_next_line(fd);
	if (ft_strlen(line) > 1)
		chomp(line, '\n');
	tokens = ft_split(line, ' ');
	if (! tokens || !*tokens)
		tokens = ft_arr_free(tokens);
	line = ft_free(line);
	return (tokens);
}

static void	ft_read(int fd, t_pdata *pdata)
{
	t_type	id;
	char	**tokens;

	while (errno == 0)
	{
		id = E_INVALID;
		tokens = get_next_line_tokens(fd);
		if (! tokens)
			break ;
		id = identifier(tokens[0]);
		if (id != E_NEWLINE)
			parse_line(id, tokens, pdata);
		tokens = ft_arr_free(tokens);
	}
}

t_pdata	parser(char *scene_file_path)
{
	int		fd;
	t_pdata	pdata;

	pdata.scene = empty_scene();
	pdata.camera = ft_camera(0, 0, 0);
	fd = -1;
	if (validate_path(scene_file_path) == 0)
		fd = open(scene_file_path, O_RDONLY);
	if (fd < 0)
	{
		failed_to_open_file(scene_file_path);
		return (pdata);
	}
	ft_read(fd, &pdata);
	return (pdata);
}
