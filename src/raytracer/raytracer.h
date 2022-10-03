/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:00:43 by mzarhou           #+#    #+#             */
/*   Updated: 2022/10/03 16:21:44 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H

# include "tuple.h"
# include "canvas.h"
# include "parser_.h"
# include "pair.h"
# include <stdio.h>
# include "list.h"
# include "lst_utils.h"
# include "params.h"
# include "algebra.h"
# include "matrix.h"
# include "params.h"
# include "color.h"

# define WIDTH 1280
# define HEIGHT 720

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

typedef struct s_vcamera
{
	t_tuple	origin;
	t_tuple	up;
	t_tuple	right;
	t_tuple	forward;
	float	h;
	float	w;
	float	ar;
}	t_vcamera;

typedef struct s_inter_info
{
	t_tuple		point;
	t_tuple		normal;
	float		t;
	t_object	object;
	bool		is_shadowed;
	t_tuple		eye_v;
}	t_info;

t_ray		ft_ray(t_tuple origin, t_tuple direction);
void		init_info(t_info *info);
void		ft_solve_sphere(const t_ray ray, t_object sph_obj, t_info *info);
t_vcamera	ft_setup_camera(const t_camera camera);
void		print_camera(t_vcamera c);
t_ray		ft_setray(const t_vcamera camera, t_fpair pair);
void		ft_solve_plane(t_ray ray, t_object obj, t_info *info);
void		ft_look_inters(t_list *head, t_ray ray, t_info *info);
t_color		ft_shading(t__data *data, t_info *info);

void		cylinder_intersect(t_object obj, t_ray ray, t_info *info);
double		cy_validate_local_inters(t_ray r, t_fpair t, t_object obj);

t_tuple		local_cone_normal(t_tuple p);
void		cone_intersect(t_object obj, t_ray ray, t_info *info);

t_ray		ray_transform(t_ray ray, t_matrix transformation_matrix);
t_tuple		ft_position(t_ray r, float t);

typedef struct s_shader
{
	t_ray	ray;
	t_tuple	light_vect;
	t_tuple	light_point;
	t_color	difuse;
	t_color	light_color;
	float	light_ratio;
	t_color	specular;
	t_color	color;
}	t_shader;

t_color		ft_specular(t_shader *shader, t_info *info, t_tuple view);
double		ft_cos(t_tuple v1, t_tuple v2);

#endif
