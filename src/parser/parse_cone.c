#include "_parser.h"

t_object	parse_cone(char **tokens)
{
	t_object	cone;

	cone = (t_object){};
	if (ft_arr_size(tokens) != 6)
		return (invalid_argements("cone"), cone);
	cone = new_cone(
		get_position_point(tokens[1]),
		get_orientation_vect3(tokens[2]),
		(t_fpair){{ft_stod(tokens[3]), ft_stod(tokens[4])}},
		get_color(tokens[5])
	);
	if (errno)
		invalid_argements("cone");
	return (cone);
}
