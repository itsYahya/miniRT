#include "_parser.h"

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

static t_color	rgb_to_color(t_rgb data)
{
	return ft_color(
		(float)data.r / 255.0f,
		(float)data.g / 255.0f,
		(float)data.b / 255.0f
		);
}

t_color	get_color(char *token)
{
	t_color	output;
	t_rgb	rgb;
	char	**colors;

	output = ft_color(0, 0, 0);
	colors = ft_split(token, ',');
	if (
		ft_arr_size(colors) != 3
		|| !is_int(colors[0])
		|| !is_int(colors[1])
		|| !is_int(colors[2])
	)
		return (ft_arr_free(colors), errno = 1, output);

	rgb.r = ft_atoi(colors[0]);
	rgb.g = ft_atoi(colors[1]);
	rgb.b = ft_atoi(colors[2]);
	colors = ft_arr_free(colors);
	if (! ft_check_rgb(rgb))
		return (errno = 1, output);
	return (rgb_to_color(rgb));
}
