#include "tests.h"

static void	test_transformation_matrix_for_default_orientation()
{
	t_tuple	from = point(0, 0, 0);
	t_tuple	to = point(0, 0, -1);
	t_tuple	up = vector(0, 1, 0);
	t_matrix t = view_transform(from, to, up);
	assert(matrix_equal(t, IDENTITY_MATRIX));
}

static void transformation_matrix_looking_prositive_z()
{
	t_tuple from = point(0, 0, 0);
	t_tuple to = point(0, 0, 1);
	t_tuple	up = vector(0, 1, 0);
	t_matrix t = view_transform(from, to, up);
	assert(matrix_equal(t, scale(-1, 1, -1)));
}

static void	test_transformation_matrix_moves_the_world()
{
	t_tuple	from = point(0, 0, 8);
	t_tuple	to = point(0, 0, 0);
	t_tuple up = vector(0, 1, 0);
	t_matrix t = view_transform(from, to, up);
	assert(matrix_equal(t, translate(0, 0, -8)));
}

static void	test_arbitrary_view_transformation()
{
	t_tuple	from = point(1, 3, 2);
	t_tuple	to = point(4, -2, 8);
	t_tuple up = vector(1, 1, 0);
	t_matrix t = view_transform(from, to, up);
	t_matrix expected = (t_matrix){{
		-0.50709, 0.50709, 0.67612, -2.36643,
		0.76772, 0.60609, 0.12122, -2.82843,
		-0.35857, 0.59761, -0.71714, 0.00000,
		0.00000, 0.00000, 0.00000, 1.00000
	}};
	assert(matrix_equal(t, expected));
}

void	test_view_transform()
{
	printf("=> view transform test: ");
	test_transformation_matrix_for_default_orientation();
	transformation_matrix_looking_prositive_z();
	test_transformation_matrix_moves_the_world();
	test_arbitrary_view_transformation();
	printf("OK\n");
}
