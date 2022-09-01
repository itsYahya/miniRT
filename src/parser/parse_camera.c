#include "sceneMaterial.h"
#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "mutils.h"
#include <errno.h>

static double	get_fov(const char *arg)
{
	double	result;

	result = ft_stod(arg);
	if (result < 0 || result > 180)
		errno = 1;
	return (result);
}

static t_vect3	get_orientation_vect3(const char	*arg)
{
	t_vect3 vct3 = get_vect3(arg);
	if (
		vct3.x > 1 || vct3.x < -1
		|| vct3.y > 1 || vct3.y < -1
		|| vct3.z > 1 || vct3.z < -1
	)
		errno = 1;
	return vct3;
}

static void	print_error_exit()
{
	printf("camera parser: invalid cordinates\n");
	exit(1);
}

void	parseCamera(char **tokens, t__data *data)
{
	if (ft_arr_size(tokens) != 4)
		print_error_exit();
	data->camera.coordinates = get_vect3(tokens[1]);
	data->camera.orientation_vect = get_orientation_vect3(tokens[2]);
	data->camera.fov = get_fov(tokens[3]);
	if (errno)
		print_error_exit();
}
