#include "raytracer.h"

t_scene	empty_scene()
{
	return (t_scene){
		.objects = NULL,
		.lights = NULL
	};
}

t_scene	default_scene()
{
	t_scene scene = empty_scene();
	t_light light = point_light(point(-10, 10, -10), ft_color(1, 1, 1), 1);

	t_object s1 = ft_sphere();
	s1.material.color = ft_color(0.8, 1.0, 0.6);
	s1.material.diffuse = 0.7;
	s1.material.specular = 0.2;

	t_object s2 = ft_sphere();
	set_transform(&s2, scale(0.5, 0.5, 0.5));

	add_object(&scene, s1);
	add_object(&scene, s2);
	add_light(&scene, light);
	return (scene);
}

void print_scene_info(t_scene scene)
{
	t_list	*objects;
	t_list	*lights;
	t_object	obj;

	printf("scene info: \n");
	objects = scene.objects;
	lights = scene.lights;
	printf("lights: %d\n", ft_lstsize(lights));
	printf("objects: %d\n", ft_lstsize(objects));
	while (objects)
	{
		obj = *get_object(objects);
		printf("=> %c, color: ", obj.type);
		print_color(obj.material.color);
		objects = objects->next;
	}
}
