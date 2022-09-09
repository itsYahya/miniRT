#ifndef MINIRT_H
#define MINIRT_H

#include "list.h"
#include "objects.h"
#include "ray.h"
#include "pair.h"
#include "canvas.h"

#define HEIGHT 720.0f
#define WIDTH  1280.0f

typedef struct s__data
{
	t_light			light;
	t_camera		camera;
	t_ambLightning	ambient;
	t_list			*objects;
}	t__data;


//mlx events functions
void	ft_setup_mlxevnets(void *win, t__data *data, t_canvas canvas);

#endif
