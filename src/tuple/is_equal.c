/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_equal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:51:20 by mzarhou           #+#    #+#             */
/*   Updated: 2022/10/03 15:51:31 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"
#include "tuple.h"
#include <stdbool.h>

bool	is_equal(t_tuple t1, t_tuple t2)
{
	return (
		equal(t1.x, t2.x) && equal(t1.y, t2.y) && equal(t1.z, t2.z)
		&& equal(t1.w, t2.w));
}
