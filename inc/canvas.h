#ifndef CANVAS_H
# define CANVAS_H

# include "tuple.h"
# include <stdint.h>
# include "mlx.h"

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

typedef union u_color t_color;
union u_color
{
	uint32_t	color;
	struct
	{
		uint8_t	r;
		uint8_t	g;
		uint8_t	b;
		uint8_t	a;
	};
};

t_color		ft_color(uint8_t r, uint8_t g, uint8_t b);
t_color		ft_hadamard_product(t_color c1, t_color c2);
t_canvas	ft_canvas(float width, float height);
void		ft_destroy_canvas(t_canvas canvas);
void		ft_write_pixel(t_canvas c, int x, int y, t_color color);
uint32_t*	ft_pixel_at(t_canvas c, int x, int y);

#endif
