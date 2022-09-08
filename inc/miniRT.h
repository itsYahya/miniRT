#ifndef MINIRT_H
#define MINIRT_H

#include "list.h"
#include "objects.h"
#include "ray.h"
#include "pair.h"
#include "canvas.h"

#define HEIGHT 1080.0f
#define WIDTH  1920.0f

typedef struct s__data
{
	t_light			light;
	t_camera		camera;
	t_ambLightning	ambient;
	t_list			*objects;
}	t__data;


void	renderer_rt(t__data *data);
void	ft_solve_sphere(const t_ray ray, t_sphere sphere, float *t, t_color *color);
void	ft_setup_camera(t_vcamera *vcamera, const t_camera camera);
void	ft_setray(const t_vcamera camera, t_ray *ray, t_pair pair);

//mlx events functions
void	ft_setup_mlxevnets(void *win, t__data *data, t_canvas canvas);
#endif
