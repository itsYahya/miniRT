#include "raytracer.h"
#include <stdlib.h>
#include <string.h>

void	destroy_scene(t_scene w)
{
	ft_lstclear(&w.objects, free);
	ft_lstclear(&w.lights, free);
}

void	add_object(t_scene *scene, t_object obj)
{
	t_object *object_ptr;

	if (errno != 0)
		return ;
	object_ptr =  (t_object*)malloc(sizeof(t_object));
	if (! object_ptr)
	{
		printf("failed to object to scene\n");
		return ;
	}
	*object_ptr = obj;
	ft_lstadd_back(&scene->objects, ft_lstnew(object_ptr));
}

void	add_light(t_scene *scene, t_light light)
{
	t_light *light_ptr;

	if (errno != 0)
		return ;
	light_ptr = (t_light*)malloc(sizeof(t_light));
	if (! light_ptr)
	{
		printf("failed to add light to scene\n");
		return ;
	}
	*light_ptr = light;
	ft_lstadd_back(&scene->lights, ft_lstnew(light_ptr));
}

t_object	*get_object(t_list *lst)
{
	return (t_object *)lst->content;
}

t_object	*get_object_at(t_list *lst, int index)
{
	return get_object(at(lst, index));
}

t_light	*get_light(t_list *lst)
{
	return (t_light *)lst->content;
}

t_light		*get_light_at(t_list *lst, int index)
{
	return get_light(at(lst, index));
}
