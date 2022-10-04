#include "raytracer.h"

void	print_material(t_material m)
{
	printf("\tambient: %f, diffuse: %f, specular: %f, shininess: %f\n\tcolor: ",
		m.ambient, m.diffuse, m.specular, m.shininess);
	print_color(m.color);
}

static char	*get_obj_name(t_type type)
{
	if (type == E_PLANE)
		return ("plane");
	if (type == E_SPHERE)
		return ("sphere");
	if (type == E_CYLINDER)
		return ("cylinder");
	if (type == E_CONE)
		return ("cone");
	return ("invalid");
}

void	print_object(const t_object* obj)
{
	if (! obj)
		printf("null object [print_object]");
	printf("[%s]\n", get_obj_name(obj->type));
	printf("\tposition: %f, %f, %f\n", obj->position.x, obj->position.y, obj->position.z);
	print_material(obj->material);
}

void	print_scene_info(const t__data *data)
{
	t_list	*lst;

	lst = data->objects;
	while (lst)
	{
		print_object((t_object *)lst->content);
		lst = lst->next;
	}
}
