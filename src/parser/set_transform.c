/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:50:36 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/10/03 16:50:37 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_.h"

void	set_transform(t_object *obj, t_matrix transform)
{
	obj->transform = transform;
	obj->inverted_transform = inverse(transform);
	obj->transpose = ft_transpose(inverse(transform));
}
