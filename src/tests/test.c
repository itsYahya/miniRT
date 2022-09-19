#include "tests.h"

int	main()
{
	errno = 0;
	test_light();
	seprator();
	test_raysphere();
	seprator();
	test_scene();
	seprator();
	test_view_transform();
	test_camera();
}
