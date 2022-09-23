#ifndef OBJECT_H
#define OBJECT_H

# include <stdlib.h>
# include <math.h>
# include "tuple.h"
# include "list.h"
# include "matrix.h"
# include "canvas.h"
# include "matrix.h"
# include "types.h"
# include "pair.h"

# define WIDTH 1080
# define HEIGHT 720

typedef struct s_light t_light;
struct s_light
{
    t_tuple	position;
    t_color	color;
	double	ratio;
};

typedef struct s_material t_material;
struct s_material
{
	t_color	color;
	double	ambient;
	double	diffuse;
	double	specular;
	double	shininess;
};

typedef struct s_object t_object;
struct s_object
{
	t_matrix	transform;
	t_matrix	inverted_transform;
	t_matrix	transpose_matrix;
	t_material	material;
	t_type		type;
	double		min_y;
	double		max_y;
};

typedef struct s_camera t_camera;
struct s_camera
{
	double		hsize;
	double		vsize;
	double		field_of_view;
	t_matrix	transform;
	double		pixel_size;
	double		half_width;
	double		half_height;
};

typedef struct s_scene t_scene;
struct s_scene
{
	t_list	*lights;
	t_list	*objects;
};

t_scene		empty_scene();
void		add_object(t_scene *scene, t_object obj);
void		add_light(t_scene *scene, t_light light);
t_light		point_light(t_tuple position, t_color color, double ratio);
t_object	ft_sphere();
t_object	new_sphere(t_tuple coords, double radius, t_color color);
t_object	ft_plane();
t_object	new_plane(t_tuple coords, t_tuple orientation, t_color color);
t_object	infinite_cylinder();
t_object	new_cylinder(t_tuple coords, t_tuple orientation, t_fpair radius_height, t_color color);
t_object	infinite_cone();
t_object	new_cone(t_tuple coords, t_tuple orientation, t_fpair radius_height, t_color color);
t_camera	ft_camera(double hsize, double vsize, double fv);
t_matrix	view_transform(t_tuple from, t_tuple to, t_tuple up);

#endif
