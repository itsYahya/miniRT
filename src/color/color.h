/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:44:58 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/10/03 15:45:42 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <stdint.h>
# include "tuple.h"

typedef t_tuple	t_color;

t_color		ft_color(float r, float g, float b);
t_color		to_color(uint32_t raw_value);
uint32_t	raw_color(t_color color);
void		print_color(t_color c);
t_color		ft_hadamard_product(t_color c1, t_color c2);
t_color		ft_scale_color(t_color color, double ratio);
t_color		ft_add_color(t_color c1, t_color c2);
t_color		ft_multiply_color(t_color color, t_tuple scaler);
t_tuple		ft_map_color(t_color color);
t_color		ft_merge_color(t_color main, t_color add, float ratio);

#endif
