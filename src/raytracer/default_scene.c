#include "raytracer.h"

t_scene			ft_scene()
{
	return (t_scene){
		.objects = NULL,
		.lights = NULL
	};
}

t_scene			default_scene()
{
	t_scene scene = ft_scene();
	t_light light = point_light(point(-10, 10, -10), ft_color(1, 1, 1));

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
