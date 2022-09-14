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

typedef struct s_vect3
{
	double x;
	double y;
	double z;
}	t_vect3;

typedef struct s_ambLightning
{
	float	ratio;
	int		color;
} t_ambLightning;

typedef struct s_camera
{
	t_vect3	coordinates;
	t_vect3	orientation_vect;
	double	fov;
}	t_camera;

typedef struct s_light
{
	t_vect3	point;
	float	bRatio;
	int		color;
}	t_light;

typedef struct s_sphere
{
	t_vect3	center;
	float	diameter;
	int		color;
}	t_sphere;

typedef struct s_plane
{
	t_vect3	point;
	t_vect3	vect;
	int		color;
}	t_plane;

typedef struct s_cylinder
{
	t_vect3	point;
	t_vect3	vect;
	float	diameter;
	float	height;
	int		color;
}	t_cylinder;

typedef union u_object
{
	t_sphere	sphere;
	t_plane		plane;
	t_cylinder	cylinder;
}	t_uobject;

typedef struct s__data
{
	t_light			light;
	t_camera		camera;
	t_ambLightning	ambient;
	t_list			*objects;
}	t__data;


int		validatePath(char *path);
int		parser(char *path, t__data *data);
void	parseAmbLightning(char **tokens, t__data *data);
void	parseCamera(char **tokens, t__data *data);
void	parseLight(char **tokens, t__data *data);
void	parseSphere(char **tokens, t__data *data);
void	parsePlane(char **tokens, t__data *data);
void	parseCylinder(char **tokens, t__data *data);
t_vect3	get_vect3(const char *arg);
t_vect3	get_orientation_vect3(const char *arg);
float	get_ratio(const char *token);
void	multiple_elm_exit(char *id);
void	invalid_argements(char *id);
void	invalid_identifier(void);
int		get_color(char *token);

#endif
