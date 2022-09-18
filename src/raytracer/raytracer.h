#ifndef RAYTRACER_H
# define RAYTRACER_H

# include <stdlib.h>
# include <math.h>
# include "tuple.h"
# include "list.h"
# include "matrix.h"
# include "canvas.h"
# include "utils.h"
# include "object.h"
# include <stdarg.h>
# include "params.h"
# include "utils.h"
# include <stdio.h>

typedef struct s_ray t_ray;
struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
};

typedef struct s_inter t_inter;
struct s_inter
{
	float		t;
	t_object	object;
};

typedef struct s_xs t_xs;
struct s_xs
{
	int		count;
	t_inter	*inters;
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

// globals
t_inter		ft_inter(float t, t_object object);
t_xs		ft_inters(unsigned int count, ...);
t_xs		intersect(t_object object, t_ray ray);
t_tuple		normal_at(t_object object, t_tuple p);
t_inter		ft_hit(t_xs xs);
void		set_transform(t_object *obj, t_matrix transform);
void		destroy_inters(t_xs *xs);

// ray
t_ray			ft_ray(t_tuple origin, t_tuple direction);
t_tuple			ft_position(t_ray r, float t);
t_ray			ray_transform(t_ray ray, t_matrix transformation_matrix);

// sphere
t_object	ft_sphere();
t_xs		intersect_sphere(t_object object, t_ray ray);
t_tuple		sphere_normal(t_object object, t_tuple p);

// light
t_tuple			reflect(t_tuple v, t_tuple normal);
t_light			point_light(t_tuple position, t_color intensity);
t_tuple			ft_lighting(t_material material, t_light light, t_tuple position, t_tuple eyev, t_tuple normalv);

// material
t_material		ft_material();
bool			material_equal(t_material m1, t_material m2);
void			setMatAmbient(t_material *mat, float ambient);
void			setMatDiffuse(t_material *mat, float diffuse);
void			setMatSpecular(t_material *mat, float specular);
void			setMatShininess(t_material *mat, float shininess);

// world
t_world			ft_world();
t_world			default_world();
void			destroy_world(t_world w);
t_xs			intersect_world(t_world w, t_ray ray);

// color
t_color			color_at(t_world w, t_ray r);
t_color			shade_hit(t_world w, t_comps comps);
t_comps			hitpoint_info(t_inter intersection, t_ray r);

#endif
