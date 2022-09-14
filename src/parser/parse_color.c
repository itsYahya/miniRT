#include "parser_.h"

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

static int rgb_to_int(t_rgb data)
{
	int	color;

	color = 0;
	color = data.r << 16;
	color |= data.g << 8;
	color |= data.b;
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
		return (ft_arr_free(colors), errno = 1, 0);
	rgb.r = ft_atoi(colors[0]);
	rgb.g = ft_atoi(colors[1]);
	rgb.b = ft_atoi(colors[2]);
	colors = ft_arr_free(colors);
	if (!ft_check_rgb(rgb))
		return (errno = 1, 0);
	return (rgb_to_int(rgb));
}
