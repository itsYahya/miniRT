#ifndef TRANSFORM_H
# define TRANSFORM_H

# include "matrix.h"
# include <math.h>

t_matrix	translate(float x, float y, float z);
t_matrix	scale(float x, float y, float z);
t_matrix	rotate_x(float radians);
t_matrix	rotate_y(float radians);
t_matrix	rotate_z(float radians);

#endif
