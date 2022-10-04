/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_tuple.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:46:35 by mzarhou           #+#    #+#             */
/*   Updated: 2022/10/03 15:46:59 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"
#include "tuple.h"
#include <math.h>
#include <stdlib.h>

t_tuple	point(float x, float y, float z)
{
	return (tuple(x, y, z, 1));
}

t_tuple	vector(float x, float y, float z)
{
	return (tuple(x, y, z, 0));
}

t_tuple	tuple(float x, float y, float z, float w)
{
	return ((t_tuple){{x, y, z, w}});
}
