#include "h_threads.h"

void	ft_threads_lunsher(t__data *data)
{
	t_thread	threads[THREADS_NUM];
	int			index;
	t_vcamera	vcamera;
	int			step;


	index = 0;
	vcamera = ft_setup_camera(data->camera);
	step = HEIGHT / THREADS_NUM;
	while (index < THREADS_NUM)	
	{
		threads[index].begin = step * index;
		threads[index].end = step * (index + 1);
		threads[index].data = data;
		threads[index].vcamera = vcamera;
		if (index == THREADS_NUM - 1)
			threads[index].end = HEIGHT;
		if (pthread_create(&threads[index].thread, NULL, render, &threads[index]))
			exit(1);
		index++;
	}
	index = 0;
	while (index < THREADS_NUM)
		if (pthread_join(threads[index++].thread, NULL))
			exit(1);
	setup_mlxevents(data);
	ft_show_canvas(data->canvas);
	mlx_loop(data->canvas.mlx_ptr);
}
