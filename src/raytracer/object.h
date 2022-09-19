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

typedef struct s_light t_light;
struct s_light
{
    t_tuple	position;
    t_color	intensity;
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

typedef struct s_sphere t_sphere;
struct s_sphere
{

};

typedef struct s_cylinder t_cylinder;
struct s_cylinder
{

};

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
		t_sphere	sp;
		t_cylinder	cy;
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

#endif
