#ifndef ALGEBRA_H
# define ALGEBRA_H
# include <stdbool.h>
# include <stdlib.h>
# include <math.h>

# define EPSILON 0.0001
# define EPSILON_2 0.02
# define SIGN(x) x/fabs(x)

bool	equal(float a, float b);

#endif
