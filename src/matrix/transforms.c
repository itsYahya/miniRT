/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transforms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:07:09 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/10/03 16:07:10 by yel-mrab         ###   ########.fr       */
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
	transform = IDENTITY_MATRIX;
	while (++i < count)
		transform = matrix_multiply(transform, va_arg(ap, t_matrix));
	return (transform);
}
