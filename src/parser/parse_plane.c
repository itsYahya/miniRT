#include "_parser.h"

t_object	parse_plane(char **tokens)
{
	t_object	plane;

	plane = (t_object){};
	if (ft_arr_size(tokens) != 4)
	{
		invalid_argements("plane");
		return (plane);
	}
    plane = new_plane(
        get_position_point(tokens[1]),
        get_orientation_vect3(tokens[2]),
        get_color(tokens[3])
	);
	if (errno)
		invalid_argements("plane");
	return (plane);
}
