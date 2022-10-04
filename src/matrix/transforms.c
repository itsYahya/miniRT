/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transforms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:07:09 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/10/03 17:13:13 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix	transforms(int count, ...)
{
	int			i;
	va_list		ap;
	t_matrix	transform;

	va_start(ap, count);
	i = -1;
	transform = identity_matrix();
	while (++i < count)
		transform = matrix_multiply(transform, va_arg(ap, t_matrix));
	return (transform);
}
