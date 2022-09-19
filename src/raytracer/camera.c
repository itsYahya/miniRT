#include "raytracer.h"

t_matrix	view_transform(t_tuple from, t_tuple to, t_tuple up)
{
	t_tuple		forward;
	t_tuple		left;
	t_tuple		true_up;
	t_matrix	orientation_transform;

	up = normalize(up);
	forward = normalize(subst_tuple(to, from));
	left = cross(forward, up);
	true_up = cross(left, forward);
	orientation_transform = (t_matrix){{
		left.x, left.y, left.z, 0,
		true_up.x, true_up.y, true_up.z, 0,
		-forward.x, -forward.y, -forward.z, 0,
		0, 0, 0, 1
	}};
	return matrix_multiply(orientation_transform, translate(-from.x, -from.y, -from.z));
}

t_camera	ft_camera(double hsize, double vsize, double fv)
{
	t_camera	c;
	double		aspect_ratio;
	double		half_view;

	half_view = tan(fv / 2);
	aspect_ratio = hsize / vsize;

	if (aspect_ratio >= 1) {
		c.half_width = half_view;
		c.half_height = half_view / aspect_ratio;
	} else {
		c.half_width = half_view * aspect_ratio;
		c.half_height = half_view;
	}
	c.hsize = hsize;
	c.vsize = vsize;
	c.field_of_view = fv;
	c.transform = IDENTITY_MATRIX;
	c.pixel_size = (2 * c.half_width) / c.hsize;
	return (c);
}

t_ray		ray_for_pixel(t_camera c, double x, double y)
{
	// offset from edge to the center of the canvas
	double	xoffset = (x + 0.5) * c.pixel_size;
	double	yoffset = (y + 0.5) * c.pixel_size;

	double	world_x = c.half_width - xoffset;
	double	world_y = c.half_height - yoffset;

	t_tuple pixel = matrix_tuple_multiply(inverse(c.transform), point(world_x, world_y, -1));
	t_tuple origin = matrix_tuple_multiply(inverse(c.transform), point(0, 0, 0));
	t_tuple	direction = normalize(subst_tuple(pixel, origin));
	return (ft_ray(origin, direction));
}

void	print_camera_info(t_camera c)
{
	printf("camera info: \n");
	printf("hsize: %f, vsize: %f, field_of_view: %f\n", c.hsize, c.vsize, c.field_of_view);
	printf("transform: \n");
	print_matrix(c.transform);
}
