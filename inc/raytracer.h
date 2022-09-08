#ifndef RAYTRACER_H
# define RAYTRACER_H

# include "tuple.h"
# include "list.h"
# include "matrix.h"

typedef struct s_ray t_ray;
struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
};

typedef struct s_object t_object;
struct s_object
{
	t_matrix	transform_matrix;
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

t_ray			ft_ray(t_tuple origin, t_tuple direction);
t_tuple			ft_position(t_ray r, float t);
t_xs			ft_intersect(t_object s, t_ray r);
t_object		ft_sphere();
t_intersection	ft_intersection(float t, t_object object);
t_xs			ft_intersections(unsigned int count, ...);
void			destroy_intersections(t_xs *xs);
t_intersection	ft_hit(t_xs xs);

t_ray			ft_transform(t_ray ray, t_matrix transformation_matrix);
void			set_transform(t_object *object, t_matrix matrix);

#endif
