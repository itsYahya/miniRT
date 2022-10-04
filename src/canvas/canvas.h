/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:44:21 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/10/03 15:44:22 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

# include "tuple.h"
# include <stdint.h>
# include "mlx.h"
# include "color.h"
# include "utils.h"

typedef struct s_canvas	t_canvas;
struct s_canvas
{
	int			width;
	int			height;
	void		*mlx_ptr;
	void		*mlx_win;
	void		*img;
	uint32_t	*img_data;
};

int			ft_canvas(t_canvas *canvas, float width, float height);
void		destroy_canvas(t_canvas canvas);
void		ft_write_pixel(t_canvas c, int x, int y, t_color color);
uint32_t	*ft_pixel_at(t_canvas c, int x, int y);
void		ft_show_canvas(t_canvas canvas);

#endif
