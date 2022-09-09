#ifndef CANVAS_H
# define CANVAS_H

# include "tuple.h"
# include <stdint.h>
# include "mlx.h"
# include <stdio.h>

typedef t_tuple t_color;

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

t_color		ft_color(float r, float g, float b);
t_color		ft_hexcolor(uint32_t color);
uint32_t	to_raw_color(t_color c);
bool 		color_equal(t_color c1, t_color c2);

t_canvas	ft_canvas(float width, float height);
void		ft_destroy_canvas(t_canvas canvas);
void		ft_write_pixel(t_canvas c, int x, int y, uint32_t color);
uint32_t*	ft_pixel_at(t_canvas c, int x, int y);
void		ft_show_canvas(t_canvas canvas);
void		renderer();

void		print_color(t_color c);

#endif
