
#include <stdio.h>
#include "_parser.h"

static double	get_fov(const char *arg)
{
	double	result;

	result = ft_stod(arg);
	if (result < 0 || result > 180)
		errno = 1;
	return (result);
}

t_camera	parse_camera(char **tokens)
{
	float			fv;
	t_tuple			position;
	t_tuple			look_at;
	t_camera		c;

	c = ft_camera(0, 0, 0);
	if (ft_arr_size(tokens) != 4)
	{
		invalid_argements("camera");
		return (c);
	}
	position = get_position_point(tokens[1]);
	look_at = get_position_point(tokens[2]);
	fv = get_fov(tokens[3]) * M_PI / 180;
	if (errno)
	{
		invalid_argements("camera");
		return (c);
	}
	c = ft_camera(WIDTH, HEIGHT, fv);
	c.transform = view_transform(position, look_at, vector(0, 1, 0));
	return (c);
}
