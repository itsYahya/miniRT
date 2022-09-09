#ifndef RANDERER_H
#define RANDERER_H

#include "miniRT.h"

typedef struct s_inter_info
{
	t_color	color;
	t_tuple	point;
	float	t;
}	t_info;

void	renderer_rt(t__data *data);
void	ft_solve_sphere(const t_ray ray, t_sphere sphere, t_info *info);
void	ft_setup_camera(t_vcamera *vcamera, const t_camera camera);
void	ft_setray(const t_vcamera camera, t_ray *ray, t_pair pair);

#endif
