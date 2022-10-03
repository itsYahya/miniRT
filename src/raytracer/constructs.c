/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:56:22 by mzarhou           #+#    #+#             */
/*   Updated: 2022/10/03 15:56:27 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_tuple	ft_position(t_ray r, float t)
{
	return (add_tuple(r.origin, multiply_tuple(r.direction, t)));
}
