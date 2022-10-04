/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:46:46 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/10/03 15:46:47 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_tuple	ft_map_color(t_color color)
{
	t_tuple	res;

	res.x = color.r / 255;
	res.y = color.g / 255;
	res.z = color.b / 255;
	return (res);
}
