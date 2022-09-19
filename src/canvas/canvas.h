#ifndef CANVAS_H
# define CANVAS_H

# include "tuple.h"
# include <stdint.h>
# include "mlx.h"
# include <stdio.h>
# include "algebra.h"
# include "color.h"

typedef struct s_canvas t_canvas;
struct s_canvas
{
	int			width;
	int			height;
	void 		*mlx_ptr;
	void 		*mlx_win;
	void 		*img;
	uint32_t	*img_data;
};

t_canvas	ft_canvas(double width, double height);
void		ft_destroy_canvas(t_canvas canvas);
void		ft_write_pixel(t_canvas c, int x, int y, uint32_t color);
uint32_t*	ft_pixel_at(t_canvas c, int x, int y);
void		ft_show_canvas(t_canvas canvas);


#endif
