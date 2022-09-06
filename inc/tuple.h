#ifndef TUPLE_H
# define TUPLE_H
# include <stdbool.h>
# include <math.h>

typedef struct s_tuple t_tuple;

typedef struct s_tuple t_tuple;
struct s_tuple
{
	struct
	{
		float	x;
		float	y;
		float	z;
		float	w;
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


#endif
