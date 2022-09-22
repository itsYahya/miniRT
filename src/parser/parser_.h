#ifndef PARSER__H
#define PARSER__H

# include "tuple.h"
# include "list.h"
# include "types.h"
# include "utils.h"
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "matrix.h"
# include "color.h"

typedef t_tuple t_vect3;

typedef struct s_ambLightning
{
	float	ratio;
	t_color	color;
} t_ambLightning;

typedef struct s_camera
{
	t_tuple	coordinates;
	t_tuple	orientation_vect;
	double	fov;
}	t_camera;

typedef struct s_light
{
	t_tuple point;
	float	bRatio;
	t_color	color;
}	t_light;

typedef struct s_sphere
{
	float	diameter;
}	t_sphere;

typedef struct s_plane
{
	t_tuple		orientation;
}	t_plane;

typedef struct s_cylinder
{
	t_tuple		orientation;
	float		diameter;
	float		height;
	float		min_y;
	float		max_y;
}	t_cylinder;

typedef struct s_object t_object;
struct s_object
{
	union
	{
		t_tuple	position;
		t_tuple	p;
	};
	t_color		color;
	t_type		type;
	t_matrix	transform;
	t_matrix	inverted_transform;
	t_matrix	transpose;
	union
	{
		t_sphere	sphere;
		t_plane		plane;
		t_cylinder	cy;
	};
};

typedef struct s__data
{
	t_light			light;
	t_camera		camera;
	t_ambLightning	ambient;
	t_list			*objects;
}	t__data;


int			validatePath(char *path);
int			parser(char *path, t__data *data);
void		parseAmbLightning(char **tokens, t__data *data);
void		parseCamera(char **tokens, t__data *data);
void		parseLight(char **tokens, t__data *data);
void		parseSphere(char **tokens, t__data *data);
void		parsePlane(char **tokens, t__data *data);
void		parseCylinder(char **tokens, t__data *data);
t_tuple		get_orientation_vect3(const char *arg);
t_tuple		get_position_point(const char *arg);
float		get_ratio(const char *token);
void		multiple_elm_exit(char *id);
void		invalid_argements(char *id);
void		invalid_identifier(void);
uint32_t	get_color(char *token);

t_matrix	orientation_transform(t_tuple coords, t_tuple orientation);
void		set_transform(t_object *obj, t_matrix transform);
#endif
