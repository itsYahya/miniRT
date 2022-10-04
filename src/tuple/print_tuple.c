/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tuple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:52:18 by mzarhou           #+#    #+#             */
/*   Updated: 2022/10/03 15:52:19 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"
#include <stdio.h>

void	print_tuple(t_tuple t)
{
	printf("%f, %f, %f, %f\n", t.x, t.y, t.z, t.w);
}

void	print_point(t_tuple t)
{
	printf("%f, %f, %f\n", t.x, t.y, t.z);
}

void	print_vector(t_tuple t)
{
	print_point(t);
}
