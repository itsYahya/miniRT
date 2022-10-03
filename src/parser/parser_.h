/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:31:10 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/10/03 16:55:32 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER__H
# define PARSER__H

# include "tuple.h"
# include "list.h"
# include "types.h"
# include "utils.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "matrix.h"
# include "color.h"
# include "canvas.h"

int			*ft_errno(void);

# define errno *ft_errno()

typedef t_tuple	t_vect3;

typedef struct s_amblightning
{
	float	ratio;
	t_color	color;
}	t_amblightning;

typedef struct s_camera
{
	t_tuple	coordinates;
	t_tuple	orientation_vect;
	double	fov;
}	t_camera;

typedef struct s_light
{
	t_tuple	point;
	float	bratio;
	t_color	color;
}	t_light;

typedef struct s_sphere
{
	float	diameter;
}	t_sphere;

typedef struct s_plane
{
	t_tuple	orientation;
}	t_plane;

typedef struct s_cylinder
{
	float	min_y;
	float	max_y;
}	t_cylinder;

typedef struct s_cone
{
	float	min_y;
	float	max_y;
}	t_cone;
typedef struct s_material
{
	t_color	color;
	float	ambient;
	float	specular;
	float	shininess;
	float	diffuse;
}	t_material;

typedef struct s_object
{
	union
	{
		t_tuple	position;
		t_tuple	p;
	};
	t_type		type;
	t_matrix	transform;
	t_matrix	inverted_transform;
	t_matrix	transpose;
	t_material	material;
	union
	{
		t_sphere	sphere;
		t_plane		plane;
		t_cylinder	cy;
		t_cone		cn;
	};
}	t_object;

typedef struct s__data
{
	t_camera		camera;
	t_amblightning	ambient;
	t_list			*objects;
	t_list			*lights;
	t_canvas		canvas;
}	t__data;

int			validate_path(char *path);
int			parser(char *path, t__data *data);
int			parse_amblightning(char **tokens, t__data *data);
int			parse_camera(char **tokens, t__data *data);
int			parse_light(char **tokens, t__data *data);
int			parse_sphere(char **tokens, t__data *data);
int			parse_plane(char **tokens, t__data *data);
int			parse_cylinder(char **tokens, t__data *data);
int			parse_cone(char **tokens, t__data *data);
t_tuple		get_orientation_vect3(const char *arg);
t_tuple		get_position_point(const char *arg);
float		get_ratio(const char *token);
void		multiple_elm(char *id);
void		invalid_argements(char *id);
void		invalid_identifier(char *id);
void		invalid_file(void);
uint32_t	get_color(char *token);
void		ft_set_material(t_object *object, char **tokens,
				int index, t_color color);
t_matrix	orientation_transform(t_tuple coords, t_tuple orientation);
void		set_transform(t_object *obj, t_matrix transform);

#endif
