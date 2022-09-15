#ifndef RAYTRACER_H
# define RAYTRACER_H

# include "tuple.h"
# include "canvas.h"
# include "parser_.h"
# include "pair.h"
# include <stdio.h>
# include "list.h"
# include "lst_utils.h"
# include "params.h"
# include "algebra.h"
# include "matrix.h"
# include "params.h"

# define WIDTH 600
# define HEIGHT 600

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

typedef struct s_vcamera
{
	t_tuple	origin;
	t_tuple	up;
	t_tuple	right;
	t_tuple	forward;
	float	h;
	float	w;
	float	ar;
}	t_vcamera;

typedef struct s_inter_info
{
	t_color	color;
	t_tuple	point;
	t_tuple	normal;
	float	t;
}	t_info;

typedef struct s_scene t_scene;
struct s_scene
{

};

void		render(t__data *data);
void		ft_solve_sphere(const t_ray ray, t_object sph_obj, t_info *info);
t_vcamera	ft_setup_camera(const t_camera camera);
t_ray		ft_setray(const t_vcamera camera, t_pair pair);
// t_info		ft_lightning(t_light light);

uint32_t	cylinder_intersect(t_cylinder cy, t_ray ray);
t_cylinder	ft_cylinder();

#endif
