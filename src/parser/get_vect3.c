#include "_parser.h"

static t_vect3	get_vect3(const char *arg)
{
	char	**coordinates = ft_split(arg, ',');
	t_vect3	vect3;

	if (ft_arr_size(coordinates) != 3)
		return (ft_arr_free(coordinates), errno = 1, (t_vect3){{0, 0, 0, 0}});
	vect3 = (t_vect3){{
		ft_stod(coordinates[0]),
		ft_stod(coordinates[1]),
		ft_stod(coordinates[2]),
		0
	}};
	return (ft_arr_free(coordinates), vect3);
}

t_vect3	get_orientation_vect3(const char	*arg)
{
	t_vect3	vct3 = get_vect3(arg);
	vct3.w = 0;
	if (
		vct3.x > 1 || vct3.x < -1
		|| vct3.y > 1 || vct3.y < -1
		|| vct3.z > 1 || vct3.z < -1
	)
		errno = 1;
	return vct3;
}

t_tuple	get_position_point(const char *arg)
{
	t_tuple	vct3;

	vct3 = get_vect3(arg);
	vct3.w = 1;
	return (vct3);
}
