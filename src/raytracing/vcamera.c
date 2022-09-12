#include "miniRT.h"
#include "canvas.h"
#include "pair.h"
#include <stdio.h>
#include "ray.h"
#include "objects.h"

static double	ft_degrees_to_radians(const float angel)
{
	return (angel * M_PI / 180);
}

void	ft_setup_camera(t_vcamera *vcamera, const t_camera camera)
{
	vcamera->ar = (float)WIDTH / (float)HEIGHT;
	vcamera->h = tan(ft_degrees_to_radians(camera.fov/2));
	vcamera->w = vcamera->h * vcamera->ar;
	vcamera->origin = point(camera.coordinates.x, camera.coordinates.y, camera.coordinates.z);
	vcamera->forward = vector(camera.orientation_vect.x, camera.orientation_vect.y, camera.orientation_vect.z);
	vcamera->up = normalize(cross(vcamera->forward, vector(0, 1, 0)));
	vcamera->right = normalize(cross(vcamera->forward, vcamera->up));
}
