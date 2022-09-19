#include "get_next_line.h"
#include "utils.h"
#include <fcntl.h>
#include "matrix.h"
#include <errno.h>
#include "matrix.h"
#include "canvas.h"
#include "raytracer.h"
#include "algebra.h"
#include "timer.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int		i;
	(void)	i;

	t_scene	scene = ft_scene();

	// floor
	t_object floor = ft_sphere();
	set_transform(&floor, scale(10, 0.01, 10));
	floor.material.color = ft_color(1, 0.9, 0.9);
	floor.material.specular = 0;
	add_object(&scene, floor);

	// left_wall
	t_object left_wall = ft_sphere();
	set_transform(&left_wall, transforms(4,
		translate(0, 0, 5),
		rotate_y(-M_PI_4),
		rotate_x(M_PI_2),
		scale(10, 0.01, 10)
	));
	left_wall.material = floor.material;
	add_object(&scene, left_wall);

	// right_wall
	t_object right_wall = ft_sphere();
	set_transform(&right_wall, transforms(4,
		translate(0, 0, 5),
		rotate_y(M_PI_4),
		rotate_x(M_PI_2),
		scale(10, 0.01, 10)
	));
	add_object(&scene, right_wall);

	// middle
	t_object middle = ft_sphere();
	set_transform(&middle, translate(-0.5, 1, 0.5));
	middle.material = ft_material();
	middle.material.color = ft_color(0.1, 1, 0.5);
	middle.material.diffuse = 0.7;
	middle.material.specular = 0.3;
	add_object(&scene, middle);

	// right
	t_object	right = ft_sphere();
	set_transform(&right, transforms(2,
		translate(1.5, 0.5, -0.5),
		scale(0.5, 0.5, 0.5)
	));
	right.material = middle.material;
	right.material.color = ft_color(0.5, 1, 0.1);
	add_object(&scene, right);

	// left
	t_object left = ft_sphere();
	set_transform(&left, transforms(2,
		translate(-1.5, 0.33, -0.75),
		scale(0.33, 0.33, 0.33)
	));
	left.material = right.material;
	left.material.color = ft_color(1, 0.8, 0.1);
	add_object(&scene, left);

	// light
	t_light	light = point_light(point(-10, 10, -10), ft_color(1, 1, 1));
	add_light(&scene, light);

	// camera
	t_camera camera = ft_camera(420, 360, M_PI / 3);
	camera.transform = view_transform(point(0, 1.5, -5), point(0, 1, 0), vector(0, 1, 0));

	// render
	start_timer("render");
	t_canvas canvas = render(camera, scene);
	end_timer("render");
	destroy_timer();
	ft_show_canvas(canvas);
	mlx_loop(canvas.mlx_ptr);
}
