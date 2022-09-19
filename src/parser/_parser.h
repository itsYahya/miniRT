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
# include "object.h"

typedef t_tuple	t_vect3;
typedef	struct s_pdata t_pdata;
struct s_pdata
{
	t_scene		scene;
	t_camera	camera;
};

t_pdata	parser(char *scene_file_path);

// parser components
t_camera	parse_camera(char **tokens);
t_light		parse_light(char **tokens);
t_object	parse_sphere(char **tokens);
// void		parse_plane(char **tokens, t_pdata *data);
// void		parse_cylinder(char **tokens, t_pdata *data);
// void		parse_ambient_lightning(char **tokens, t_pdata *data);

// parser utils
int			validate_path(char *path);
t_tuple		get_orientation_vect3(const char *arg);
t_tuple		get_position_point(const char *arg);
double		get_ratio(const char *token);
t_color		get_color(char *token);

// error handling
void		multiple_elm_exit(char *id);
void		invalid_argements(char *id);
void		invalid_identifier(void);
void		failed_to_open_file(char *path);

#endif
