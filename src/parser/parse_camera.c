
#include <stdio.h>
#include "parser_.h"

static double	get_fov(const char *arg)
{
	double	result;

	result = ft_stod(arg);
	if (result < 0 || result > 180)
		errno = 1;
	return (result);
}

void	parseCamera(char **tokens, t__data *data)
{
	if (ft_arr_size(tokens) != 4)
		invalid_argements("camera");
	data->camera.coordinates = get_position_point(tokens[1]);
	data->camera.orientation_vect = get_orientation_vect3(tokens[2]);
	data->camera.fov = get_fov(tokens[3]);
	if (errno)
		invalid_argements("camera");
}
