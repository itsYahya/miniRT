#include "raytracer.h"

t_scene			ft_scene()
{
	return (t_scene){
		.objects = NULL
	};
}

t_scene			default_scene()
{
	t_list		*objects;
	t_object	*obj;

	objects = NULL;
	obj = malloc(sizeof(t_object));
	*obj = ft_sphere();
	ft_lstadd_back(&objects, ft_lstnew(obj));
	obj = malloc(sizeof(t_object));
	*obj = ft_sphere();
	obj->transform = scale(0.5, 0.5, 0.5);
	ft_lstadd_back(&objects, ft_lstnew(obj));
	return (t_scene){
		.light = point_light(point(-10, 10, -10), ft_color(1, 1, 1)),
		.objects = objects
	};
}

void			destroy_scene(t_scene w)
{
	ft_lstclear(&w.objects, free);
}
