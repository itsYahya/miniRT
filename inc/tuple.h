#ifndef TUPLE_H
# define TUPLE_H
# include <stdbool.h>
# include <math.h>

typedef union u_tuple t_tuple;
union u_tuple
{
	struct
	{
		float x;
		float y;
		float z;
		float w;
	};
	struct
	{
		float r;
		float g;
		float b;
		float a;
	};
};


t_tuple	point(float x, float y, float z);
t_tuple	vector(float x, float y, float z);
t_tuple tuple(float x, float y, float z, float w);

t_tuple	add_tuple(t_tuple pv, t_tuple v);
t_tuple	subst_tuple(t_tuple p, t_tuple pv);
t_tuple	negate_tuple(t_tuple v);
t_tuple	multiply_tuple(t_tuple v, float scalar);
t_tuple	divide_tuple(t_tuple v, float scalar);

float	dot(t_tuple v1, t_tuple v2);
float	magnitude(t_tuple v);
t_tuple	normalize(t_tuple v);
t_tuple	cross(t_tuple a, t_tuple b);

t_tuple	ft_hadamard_product(t_tuple c1, t_tuple c2);

void	print_tuple(t_tuple t);
void	print_point(t_tuple t);
void	print_vector(t_tuple t);

#endif
