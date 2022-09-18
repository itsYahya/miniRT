#include "raytracer.h"

t_world			ft_world()
{
	return (t_world){
		.objects = NULL
	};
}

t_world			default_world()
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
	return (t_world){
		.light = point_light(point(-10, 10, -10), ft_color(1, 1, 1)),
		.objects = objects
	};
}

void			destroy_world(t_world w)
{
	ft_lstclear(&w.objects, free);
}
