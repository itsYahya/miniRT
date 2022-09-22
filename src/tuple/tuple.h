#ifndef TUPLE_H
# define TUPLE_H
# include <stdbool.h>
# include <math.h>
# include "algebra.h"

typedef union u_tuple t_tuple;
union u_tuple
{
	struct
	{
		double x;
		double y;
		double z;
		double w;
	};
	struct
	{
		double r;
		double g;
		double b;
		double a;
	};
};


t_tuple	point(double x, double y, double z);
t_tuple	vector(double x, double y, double z);
t_tuple tuple(double x, double y, double z, double w);

bool	is_equal(t_tuple t1, t_tuple t2);

t_tuple	add_tuple(t_tuple pv, t_tuple v);
t_tuple	subst_tuple(t_tuple p, t_tuple pv);
t_tuple	negate_tuple(t_tuple v);
t_tuple	multiply_tuple(t_tuple v, double scalar);
t_tuple	divide_tuple(t_tuple v, double scalar);
t_tuple	tuple_product(t_tuple t1, t_tuple t2);

double	dot(t_tuple v1, t_tuple v2);
double	magnitude(t_tuple v);
t_tuple	normalize(t_tuple v);
t_tuple	cross(t_tuple a, t_tuple b);

void	print_tuple(t_tuple t);
void	print_point(t_tuple t);
void	print_vector(t_tuple t);

double	angle_between(t_tuple v1, t_tuple v2);

#endif
