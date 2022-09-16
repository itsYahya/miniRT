#include "raytracer.h"

t_ray	ft_setray(const t_vcamera camera, t_pair pair)
{
	t_fpair fcoords;
	t_tuple	up;
	t_tuple	right;
	t_ray	ray;

	ray.origin = camera.origin;
	fcoords.x = (float)(2 * pair.x) / (float)WIDTH - 1;
	fcoords.y = (float)(2 * pair.y) / (float)HEIGHT - 1;
	up = multiply_tuple(camera.up, camera.h * -fcoords.y);
	right = multiply_tuple(camera.right, camera.w * fcoords.x);
	ray.direction = add_tuple(camera.forward, add_tuple(up, right));
	ray.direction = normalize(ray.direction);
	return (ray);
}

t_ray		ray_transform(t_ray ray, t_matrix transformation_matrix)
{
	ray.origin = matrix_tuple_multiply(transformation_matrix, ray.origin);
	ray.direction = matrix_tuple_multiply(transformation_matrix, ray.direction);
	return (ray);
}
