#include "get_next_line.h"
#include "utils.h"
#include <fcntl.h>
#include "matrix.h"
#include <errno.h>
#include "matrix.h"
#include "canvas.h"
#include "raytracer.h"
#include "algebra.h"
#include "timer.h"
#include <errno.h>
#include "_parser.h"

int	main(int argc, char **argv)
{
	t_pdata		pdata;
	t_canvas	canvas;
	t_camera	camera;
	t_scene		scene;

	if (argc != 2)
	{
		printf("Usage: %s <scene_file>\n", argv[0]);
		return (1);
	}
	errno = 0;
	start_timer("*parsing");
	pdata = parser(argv[1]);
	end_timer("*parsing");
	if (errno != 0)
	{
		// TODO: destroy scene
		return (1);
	}
	scene = pdata.scene;
	camera = pdata.camera;
	start_timer("*render");
	canvas = render(camera, scene);
	end_timer("*render");
	destroy_timer();
	ft_show_canvas(canvas);
	mlx_loop(canvas.mlx_ptr);
}
