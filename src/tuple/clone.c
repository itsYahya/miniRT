/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:46:31 by mzarhou           #+#    #+#             */
/*   Updated: 2022/10/03 15:46:32 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

t_tuple	clone_withx(t_tuple t, float x)
{
	t.x = x;
	return (t);
}

t_tuple	clone_withy(t_tuple t, float y)
{
	t.y = y;
	return (t);
}

t_tuple	clone_withz(t_tuple t, float z)
{
	t.z = z;
	return (t);
}
