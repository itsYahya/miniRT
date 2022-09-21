#include "_parser.h"

t_object	parse_sphere(char **tokens)
{
	t_object	sphere;

	if (ft_arr_size(tokens) != 6)
	{
		invalid_argements("sphere");
		return (new_sphere(point(0, 0, 0), 0, ft_color(0, 0, 0)));
	}
	sphere = new_sphere(
		get_position_point(tokens[1]),
		ft_stod(tokens[2]),
		get_color(tokens[3])
	);
	sphere.material.diffuse = ft_stod(tokens[4]);
	sphere.material.specular = ft_stod(tokens[5]);
	if (errno)
		invalid_argements("sphere");
	return (sphere);
}
