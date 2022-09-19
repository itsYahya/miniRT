#include "_parser.h"

t_light		parse_light(char **tokens)
{
	t_tuple		position;
	float		ratio;
	t_color		color;

	if (ft_arr_size(tokens) != 4)
	{
		errno = 1;
		invalid_argements("Light");
		return (point_light(point(0, 0, 0), ft_color(0, 0, 0), 0));
	}
	position = get_position_point(tokens[1]);
	ratio = get_ratio(tokens[2]);
	color = get_color(tokens[3]);
	return (point_light(position, color, ratio));
}
