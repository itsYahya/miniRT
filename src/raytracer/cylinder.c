/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:56:30 by mzarhou           #+#    #+#             */
/*   Updated: 2022/10/03 16:08:38 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static t_tuple	local_cylinder_normal(t_tuple p)
{
	return (vector(p.x, 0, p.z));
}

static bool	is_valid_y(double y, t_object obj)
{
	return (y > obj.cy.min_y && y < obj.cy.max_y);
}

double	cy_validate_local_inters(t_ray r, t_fpair t, t_object obj)
{
	double	y0;
	double	y1;

	if (t._0 > t._1)
		swap(&t._0, &t._1);
	y0 = ft_position(r, t._0).y;
	y1 = ft_position(r, t._1).y;
	if (is_valid_y(y0, obj) && t._0 > 0)
		return (t._0);
	if (is_valid_y(y1, obj))
		return (t._1);
	return (-1);
}

static double	local_cylinder_intersect(t_object cy, t_ray r)
{
	t_params	params;
	t_fpair		t;

	params.a = pow(r.direction.x, 2) + pow(r.direction.z, 2);
	if (equal(params.a, 0.0))
		return (-1);
	params.b = 2 * (r.origin.x * r.direction.x + r.origin.z * r.direction.z);
	params.c = pow(r.origin.x, 2) + pow(r.origin.z, 2) - 1;
	params.desc = pow(params.b, 2) - 4 * params.a * params.c;
	if (params.desc < 0)
		return (-1);
	t._0 = (-params.b - sqrt(params.desc)) / (2 * params.a);
	t._1 = (-params.b + sqrt(params.desc)) / (2 * params.a);
	return (cy_validate_local_inters(r, t, cy));
}

void	cylinder_intersect(t_object obj, t_ray ray, t_info *info)
{
	double		t;
	t_ray		transformed_ray;
	t_tuple		local_hitp;

	transformed_ray = ray_transform(ray, obj.inverted_transform);
	t = local_cylinder_intersect(obj, transformed_ray);
	if (t < EPSILON || (info->t > 0 && info->t < t))
		return ;
	info->t = t;
	local_hitp = ft_position(transformed_ray, info->t);
	info->object = obj;
	info->point = matrix_tuple_multiply(obj.transform, local_hitp);
	info->point.w = 1;
	info->normal = matrix_tuple_multiply(
			obj.transpose,
			local_cylinder_normal(local_hitp)
			);
	info->normal.w = 0;
}
