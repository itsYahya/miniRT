/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:46:33 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/10/03 15:46:34 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

static double	ft_min(double f1, double f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

t_color	ft_add_color(t_color c1, t_color c2)
{
	t_color	comb;

	comb.r = ft_min(c1.r + c2.r, 255);
	comb.g = ft_min(c1.g + c2.g, 255);
	comb.b = ft_min(c1.b + c2.b, 255);
	return (comb);
}
