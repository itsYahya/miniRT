/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hadamard_product.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:47:02 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/10/03 15:47:55 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

t_color	ft_hadamard_product(t_color c1, t_color c2)
{
	return (
		ft_color(
			c1.r * c2.r / 255.0f,
			c1.g * c2.g / 255.0f,
			c1.b * c2.b / 255.0f
		));
}
