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


typedef struct s_computations t_computations;
struct s_computations
{
	float		t;
	t_object	object;
	t_tuple		point;
	t_tuple		eyev;
	t_tuple		normalv;
	bool		inside;
};

//  scene
typedef struct s_scene t_scene;
struct s_scene
{
	t_list	*lights;
	t_list	*objects;
};

void		add_object(t_scene *scene, t_object obj);
void		add_light(t_scene *scene, t_light light);
t_object	*get_object(t_list *lst);
t_object	*get_object_at(t_list *lst, int index);
t_light		*get_light(t_list *lst);
t_light		*get_light_at(t_list *lst, int index);


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
void			print_material(t_material m);

// world
t_scene			ft_scene();
t_scene			default_scene();
void			destroy_scene(t_scene w);
t_xs			intersect_scene(t_scene w, t_ray ray);

// color
t_color			color_at(t_scene w, t_ray r);
t_color			shade_hit(t_scene w, t_computations comps);
t_computations			prepare_computations(t_inter intersection, t_ray r);

// camera
t_matrix	view_transform(t_tuple from, t_tuple to, t_tuple up);
t_camera	ft_camera(float hsize, float vsize, float fv);
t_ray		ray_for_pixel(t_camera c, float x, float y);
t_canvas	render(t_camera c, t_scene s);

#endif
