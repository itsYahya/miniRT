/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:46:54 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/10/03 15:46:55 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	ft_merge_color(t_color main, t_color add, float ratio)
{
	t_color	result;
	t_tuple	scaler;

	scaler = ft_map_color(add);
	result = ft_multiply_color(main, scaler);
	result = ft_scale_color(result, ratio);
	return (result);
}
