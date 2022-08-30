#ifndef MINIRT_H
#define MINIRT_H

#include "list.h"
#include "sceneMaterial.h"


typedef struct s__data
{
	t_light			light;
	t_camera		camera;
	t_ambLightning	ambient;
	t_list			*objects;
}	t__data;

#endif