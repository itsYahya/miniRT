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

# define WIDTH 720
# define HEIGHT 480

typedef struct s_light t_light;
struct s_light
{
    t_tuple	position;
    t_color	color;
	float	ratio;
};

typedef struct s_material t_material;
struct s_material
{
	t_color	color;
	float	ambient;
	float	diffuse;
	float	specular;
	float	shininess;
};

// typedef struct s_sphere t_sphere;
// struct s_sphere
// {

// };

// typedef struct s_plane t_plane;
// struct s_plane
// {

// };

typedef struct s_object t_object;
struct s_object
{
	t_matrix	transform;
	t_matrix	inverted_transform;
	t_matrix	transpose_matrix;
	t_material	material;
	t_type		type;
	union
	{
		// t_sphere	sp;
		// t_plane		pl;
	};
};

typedef struct s_camera t_camera;
struct s_camera
{
	float		hsize;
	float		vsize;
	float		field_of_view;
	t_matrix	transform;
	float		pixel_size;
	float		half_width;
	float		half_height;
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
t_light		point_light(t_tuple position, t_color color, float ratio);
t_object	new_sphere(t_tuple coords, float radius, t_color color);
t_camera	ft_camera(float hsize, float vsize, float fv);
t_matrix	view_transform(t_tuple from, t_tuple to, t_tuple up);

#endif
