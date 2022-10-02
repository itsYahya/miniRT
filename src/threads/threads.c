#include "h_threads.h"
#include "miniRT.h"

void	ft_init_thread(int index, int step, t__data *data, t_thread *thread)
{
	thread->begin = step * index;
	thread->end = step * (index + 1);
	thread->data = data;
}

int	ft_threads_lunsher(t__data *data)
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
		threads[index].vcamera = vcamera;
		ft_init_thread(index, step, data, threads + index);
		if (index == THREADS_NUM - 1)
			threads[index].end = HEIGHT;
		if (pthread_create(&threads[index].thread, NULL, render, &threads[index]))
			return (errno = 1, errno);
		index++;
	}
	index = 0;
	while (index < THREADS_NUM)
		if (pthread_join(threads[index++].thread, NULL))
			return (errno = 1, errno);
	setup_mlxevents(data);
	ft_show_canvas(data->canvas);
	mlx_loop(data->canvas.mlx_ptr);
	return (0);
}
