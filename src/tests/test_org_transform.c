#include "tests.h"

typedef struct s_angles t_angles;
struct s_angles
{
	bool	xangle;
	bool	zangle;
};

t_angles angle_is(t_tuple org, double expected_xangle, double expected_zangle)
{
	double rad_xangle = ft_xangle(org);
	double rad_zangle = ft_zangle(org);
	double rad_expected_xangle = deg2rad(expected_xangle);
	double rad_expected_zangle = deg2rad(expected_zangle);
	t_angles angs;
	angs.xangle = equal(rad_xangle, rad_expected_xangle);
	angs.zangle = equal(rad_zangle, rad_expected_zangle);
	if (! angs.xangle || ! angs.zangle)
	{
		printf("\n");
		printf("xangle: %f, expected: %f | %f vs %f,\t\torg:", rad2deg(rad_xangle), expected_xangle, rad_xangle, rad_expected_xangle);
		print_vector(org);
		printf("zangle: %f, expected: %f | %f vs %f,\t\torg:", rad2deg(rad_zangle), expected_zangle, rad_zangle, rad_expected_zangle);
		print_vector(org);
	}
	return angs;
}

t_angles ang;
# define EXPECT(V, X, Y) \
	printf("test: %f %f %f => ", V.x, V.y, V.z); \
	ang = angle_is(V, X, Y); \
	assert(ang.xangle); \
	assert(ang.zangle); \
	printf("OK\n")

void	test_orientation_transform()
{
	printf("=> test_orientation_transform test:\n");
	EXPECT(vector(0, 0, 1), -90, 0);
	EXPECT(vector(0, 0, -1), 90, 0);

	EXPECT(vector(1, 0, 0), 0, 90);
	EXPECT(vector(-1, 0, 0), 0, -90);

	EXPECT(vector(1, 1, 0), 0, 45);
	EXPECT(vector(1, 0, 1), -90, 45);
	EXPECT(vector(1, 0, -1), 90, 45);

	EXPECT(vector(0, 1, 1), -45, 0);

	EXPECT(vector(1, 1, 1), -45, 45);
}
