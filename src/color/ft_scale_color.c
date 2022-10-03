/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scale_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:46:59 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/10/03 15:47:00 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	ft_scale_color(t_color color, double ratio)
{
	t_color	comb;

	comb.r = color.r * ratio;
	comb.g = color.g * ratio;
	comb.b = color.b * ratio;
	return (comb);
}
