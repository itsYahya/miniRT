/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vect3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:16:40 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/10/03 17:21:56 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_.h"

static t_vect3	get_vect3(const char *arg)
{
	char	**coordinates;
	t_vect3	vect3;

	coordinates = ft_split(arg, ',');
	if (ft_arr_size(coordinates) != 3)
		return (ft_arr_free(coordinates),
			*ft_errno() = 1, (t_vect3){{0, 0, 0, 0}});
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
	t_vect3	vct3;

	vct3 = get_vect3(arg);
	vct3.w = 0;
	if (vct3.x > 1 || vct3.x < -1
		|| vct3.y > 1 || vct3.y < -1
		|| vct3.z > 1 || vct3.z < -1)
		*ft_errno() = 1;
	return (vct3);
}

t_tuple	get_position_point(const char *arg)
{
	t_tuple	vct3;

	vct3 = get_vect3(arg);
	vct3.w = 1;
	return (vct3);
}
