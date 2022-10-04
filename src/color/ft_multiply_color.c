/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multiply_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:46:57 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/10/03 15:46:58 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	ft_multiply_color(t_color color, t_tuple scaler)
{
	t_color	comb;

	comb.r = color.r * scaler.x;
	comb.g = color.g * scaler.y;
	comb.b = color.b * scaler.z;
	return (comb);
}
