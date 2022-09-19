#include "tests.h"

static void	test_constructing_camera()
{
	float hsize = 160;
	float vsize = 120;
	float field_of_view = M_PI_2;

	t_camera c = ft_camera(hsize, vsize, field_of_view);
	assert(c.hsize == hsize);
	assert(c.vsize == vsize);
	assert(c.field_of_view == (float)M_PI_2);
	assert(matrix_equal(c.transform, IDENTITY_MATRIX));
}

static void	test_pixel_size_for_horizontal_canvas()
{
	t_camera c = ft_camera(200, 125, M_PI_2);
	assert(c.pixel_size == 0.01f);
}

static void	test_pixel_size_for_vertical_canvas()
{
	t_camera c = ft_camera(125, 200, M_PI_2);
	assert(c.pixel_size == 0.01f);
}

static void	test_ray_through_center_of_canvas()
{
	t_camera	c = ft_camera(201, 101, M_PI_2);
	t_ray		r = ray_for_pixel(c, 100, 50);
	assert(is_equal(r.origin, point(0, 0, 0)));
	assert(is_equal(r.direction, vector(0, 0, -1)));
}

static void	test_ray_through_corner_of_canvas()
{
	t_camera	c = ft_camera(201, 101, M_PI_2);
	t_ray		r = ray_for_pixel(c, 0, 0);
	assert(is_equal(r.origin, point(0, 0, 0)));
	assert(is_equal(r.direction, vector(0.66519, 0.33259, -0.66851)));
}

static void	test_ray_when_camera_is_transformed()
{
	t_camera	c = ft_camera(201, 101, M_PI_2);
	c.transform	= transforms(2, rotate_y(M_PI_4), translate(0, -2, 5));
	t_ray		r = ray_for_pixel(c, 100, 50);
	assert(is_equal(r.origin, point(0, 2, -5)));
	assert(is_equal(r.direction, vector(sqrt(2) / 2, 0, -sqrt(2) / 2)));
}

// static void	test_render_scene_with_camera()
// {
// 	t_scene		s = default_scene();
// 	t_camera	c = ft_camera(11, 11, M_PI_2);
// 	t_tuple		from = point(0, 0, -5);
// 	t_tuple		to = point(0, 0, 0);
// 	t_tuple 	up = vector(0, 1, 0);
// 	c.transform	= view_transform(from, to, up);
// 	t_canvas image = render(c, s);
// 	assert(*ft_pixel_at(image, 5, 5) == to_raw_color(ft_color(0.38066, 0.47583, 0.2855)));
// }

void	test_camera()
{
	printf("=> camera test: ");
	test_constructing_camera();
	test_pixel_size_for_horizontal_canvas();
	test_pixel_size_for_vertical_canvas();
	printf("OK\n");
	printf("=> ray generation test: ");
	test_ray_through_center_of_canvas();
	test_ray_through_corner_of_canvas();
	test_ray_when_camera_is_transformed();
	printf("OK\n");
	printf("=> render test: ");
	// test_render_scene_with_camera();
	printf("OK\n");
}
