#include "objects.h"
#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "mutils.h"
#include <errno.h>

t_vect3	get_vect3(const char *arg)
{
	char	**coordinates = ft_split(arg, ',');
	t_vect3	vect3;

	if (ft_arr_size(coordinates) != 3)
		return (ft_arr_free(coordinates), errno = 1, (t_vect3){0, 0, 0});
	vect3 = (t_vect3){
		ft_stod(coordinates[0]),
		ft_stod(coordinates[1]),
		ft_stod(coordinates[2])
	};
	return (ft_arr_free(coordinates), vect3);
}
