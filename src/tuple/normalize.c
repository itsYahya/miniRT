/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:52:12 by mzarhou           #+#    #+#             */
/*   Updated: 2022/10/03 15:52:12 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

t_tuple	normalize(t_tuple v)
{
	float	mangt;

	mangt = magnitude(v);
	return (tuple(
			v.x / mangt,
			v.y / mangt,
			v.z / mangt,
			v.w / mangt));
}
