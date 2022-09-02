#include "objects.h"
#include <stdio.h>
#include "parser.h"
#include <stdlib.h>
#include "mutils.h"
#include <errno.h>

void	parseCylinder(char **tokens, t__data *data)
{
	if (ft_arr_size(tokens) != 6)
		invalid_argements("cylinder");
	t_uobject* object = malloc(sizeof(t_uobject));
	object->cylinder.point = get_vect3(tokens[1]);
	object->cylinder.vect = get_orientation_vect3(tokens[2]);
	object->cylinder.diameter = ft_stod(tokens[3]);
	object->cylinder.height = ft_stod(tokens[4]);
	object->cylinder.color = get_color(tokens[5]);
	ft_lstadd_back(&data->objects, ft_lstnew(object, E_CYLINFER));
	if (errno)
	{
		ft_arr_free(tokens);
		ft_lstclear(&data->objects, free);
		invalid_argements("cylinder");
	}
}
