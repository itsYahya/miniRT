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

#endif
