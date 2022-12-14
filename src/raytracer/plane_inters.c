/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_inters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:59:33 by mzarhou           #+#    #+#             */
/*   Updated: 2022/10/03 15:59:34 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include <math.h>
#include "algebra.h"

void	ft_solve_plane(t_ray ray, t_object object, t_info *info)
{
	t_tuple	p_normal;
	t_tuple	p_point;
	float	dot1;
	float	dot2;
	float	t;

	p_point = object.p;
	p_normal = object.plane.orientation;
	dot2 = dot(p_normal, ray.direction);
	if (fabs(dot2) <= EPSILON)
		return ;
	dot1 = dot(p_normal, subst_tuple(p_point, ray.origin));
	t = dot1 / dot2;
	if (t > EPSILON && ((info->t < 0 && t > EPSILON) || t < info->t))
	{
		info->point = add_tuple(ray.origin, multiply_tuple(ray.direction, t));
		info->object = object;
		info->normal = p_normal;
		info->t = t;
	}
}
