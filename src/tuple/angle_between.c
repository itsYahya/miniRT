/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_between.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:46:28 by mzarhou           #+#    #+#             */
/*   Updated: 2022/10/03 15:47:54 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

float	angle_between(t_tuple v1, t_tuple v2)
{
	float	dot_product;
	float	magnitude_product;

	dot_product = dot(v1, v2);
	magnitude_product = magnitude(v1) * magnitude(v2);
	if (equal(magnitude_product, 0.0f))
		return (0.0f);
	return (acos(dot_product / magnitude_product));
}
