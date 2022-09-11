#ifndef RAYTRACER_H
# define RAYTRACER_H

# include <stdlib.h>
# include <math.h>
# include "tuple.h"
# include "list.h"
# include "matrix.h"
# include "canvas.h"
# include "transform.h"

typedef struct s_ray t_ray;
struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
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

typedef struct s_object t_object;
struct s_object
{
	t_matrix	transform_matrix;
	t_material	material;
};

typedef struct s_intersection t_intersection;
struct s_intersection
{
	float		t;
	t_object	object;
};

typedef struct s_xs t_xs;
struct s_xs
{
	int				count;
	t_intersection	*inters;
};

typedef struct s_light t_light;
struct s_light
{
    t_tuple	position;
    t_color	intensity;
};

typedef struct s_world t_world;
struct s_world
{
	t_light		light;
	t_list		*objects;
};

typedef struct s_comps t_comps;
struct s_comps
{
	float		t;
	t_object	object;
	t_tuple		point;
	t_tuple		eyev;
	t_tuple		normalv;
	bool		inside;
};


t_ray			ft_ray(t_tuple origin, t_tuple direction);
t_tuple			ft_position(t_ray r, float t);
t_xs			ft_intersect(t_object s, t_ray r);
t_object		ft_sphere();
t_intersection	ft_intersection(float t, t_object object);
t_xs			ft_intersections(unsigned int count, ...);
t_intersection	ft_hit(t_xs xs);
void			destroy_intersections(t_xs *xs);

t_ray			ft_transform(t_ray ray, t_matrix transformation_matrix);
void			set_transform(t_object *object, t_matrix matrix);

t_tuple			normal_at(t_object object, t_tuple point);
t_tuple			reflect(t_tuple v, t_tuple normal);
t_light			point_light(t_tuple position, t_color intensity);
t_material		ft_material();
bool			material_equal(t_material m1, t_material m2);
t_tuple			ft_lighting(t_material material, t_light light, t_tuple position, t_tuple eyev, t_tuple normalv);

t_world			ft_world();
t_world			default_world();
void			destroy_world(t_world w);
t_xs			intersect_world(t_world w, t_ray ray);

t_color			color_at(t_world w, t_ray r);
t_color			shade_hit(t_world w, t_comps comps);
t_comps			hitpoint_info(t_intersection intersection, t_ray r);

#endif
