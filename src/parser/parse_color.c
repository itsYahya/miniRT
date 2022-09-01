#include "mutils.h"
#include "parser.h"
#include "miniRT.h"
#include <stdio.h>

typedef struct s_rgb
{
	int r;
	int g;
	int b;
}	t_rgb;

static bool	ft_check_rgb(t_rgb data)
{
	if (data.r > 255 || data.r < 0)
		return (false);
	if (data.g > 255 || data.g < 0)
		return (false);
	if (data.b > 255 || data.b < 0)
		return (false);
	return (true);
}

static void	print_err_exit(char **colors)
{
	ft_arr_free(colors);
	printf("color parser: invalid input\n");
	exit(1);
}

static int rgb_to_int(t_rgb data, char **colors)
{
	int	color;

	color = 0;
	color = data.r << 16;
	color |= data.g << 8;
	color |= data.b;
	ft_arr_free(colors);
	return (color);
}

int	get_color(char *token)
{
	t_rgb	rgb;
	char	**colors;

	colors = ft_split(token, ',');
	if (ft_arr_size(colors) != 3
		|| !is_int(colors[0])
		|| !is_int(colors[1])
		|| !is_int(colors[2]))
		invalid_argements("color");
	rgb.r = ft_atoi(colors[0]);
	rgb.g = ft_atoi(colors[1]);
	rgb.b = ft_atoi(colors[2]);
	if (!ft_check_rgb(rgb))
		print_err_exit(colors);
	return (rgb_to_int(rgb, colors));
}