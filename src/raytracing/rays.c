#include "miniRT.h"
#include "canvas.h"
#include "pair.h"
#include <stdio.h>
#include "ray.h"
#include "objects.h"

void	ft_setray(const t_vcamera camera, t_ray *ray, t_pair pair)
{
	float	x;
	float	y;
	t_tuple	up;
	t_tuple	right;

	ray->origin = camera.origin;
	x = (float)(2 * pair.x) / (float)WIDTH - 1;
	y = (float)(2 * pair.y) / (float)HEIGHT - 1;
	up = multiply_tuple(camera.up, camera.h * -y);
	right = multiply_tuple(camera.right, camera.w * x);
	ray->direction = add_tuple(camera.forward, add_tuple(up, right));
	ray->direction = normalize(ray->direction);
}
