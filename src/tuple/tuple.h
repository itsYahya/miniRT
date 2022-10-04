/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:53:36 by mzarhou           #+#    #+#             */
/*   Updated: 2022/10/03 15:53:39 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_H
# define TUPLE_H
# include "algebra.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>

typedef union u_tuple	t_tuple;
union					u_tuple
{
	struct
	{
		float			x;
		float			y;
		float			z;
		float			w;
	};
	struct
	{
		float			r;
		float			g;
		float			b;
		float			a;
	};
};

t_tuple					point(float x, float y, float z);
t_tuple					vector(float x, float y, float z);
t_tuple					tuple(float x, float y, float z, float w);
bool					is_equal(t_tuple t1, t_tuple t2);

t_tuple					add_tuple(t_tuple pv, t_tuple v);
t_tuple					subst_tuple(t_tuple p, t_tuple pv);
t_tuple					negate_tuple(t_tuple v);
t_tuple					multiply_tuple(t_tuple v, float scalar);
t_tuple					divide_tuple(t_tuple v, float scalar);

float					dot(t_tuple v1, t_tuple v2);
float					magnitude(t_tuple v);
t_tuple					normalize(t_tuple v);
t_tuple					cross(t_tuple a, t_tuple b);

void					print_tuple(t_tuple t);
void					print_point(t_tuple t);
void					print_vector(t_tuple t);

t_tuple					clone_withx(t_tuple t, float x);
t_tuple					clone_withy(t_tuple t, float y);
t_tuple					clone_withz(t_tuple t, float z);

float					angle_between(t_tuple v1, t_tuple v2);
t_tuple					tuple_product(t_tuple t1, t_tuple t2);

#endif
