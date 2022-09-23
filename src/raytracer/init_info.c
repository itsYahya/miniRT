#include "raytracer.h"

void	init_info(t_info *info)
{
	info->t = -1;
	info->color.raw = 0;
	info->normal = vector(0, 0, 0);
	info->point = point(0, 0, 0);
}
