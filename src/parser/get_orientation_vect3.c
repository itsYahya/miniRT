#include "sceneMaterial.h"
#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "mutils.h"
#include <errno.h>

t_vect3	get_orientation_vect3(const char	*arg)
{
	t_vect3 vct3 = get_vect3(arg);
	if (
		vct3.x > 1 || vct3.x < -1
		|| vct3.y > 1 || vct3.y < -1
		|| vct3.z > 1 || vct3.z < -1
	)
		errno = 1;
	return vct3;
}
