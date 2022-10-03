/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:52:58 by mzarhou           #+#    #+#             */
/*   Updated: 2022/10/03 15:52:59 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"
#include "tuple.h"
#include <math.h>
#include <stdlib.h>

t_tuple	add_tuple(t_tuple pv, t_tuple v)
{
	return (tuple(
			pv.x + v.x,
			pv.y + v.y,
			pv.z + v.z,
			pv.w + v.w));
}

t_tuple	subst_tuple(t_tuple p, t_tuple pv)
{
	return (tuple(
			p.x - pv.x,
			p.y - pv.y,
			p.z - pv.z,
			p.w - pv.w));
}

t_tuple	negate_tuple(t_tuple v)
{
	return (tuple(
			-v.x,
			-v.y,
			-v.z,
			-v.w));
}

t_tuple	multiply_tuple(t_tuple v, float scalar)
{
	return (tuple(
			v.x * scalar,
			v.y * scalar,
			v.z * scalar,
			v.w * scalar));
}

t_tuple	divide_tuple(t_tuple v, float scalar)
{
	return (tuple(
			v.x / scalar,
			v.y / scalar,
			v.z / scalar,
			v.w / scalar));
}
