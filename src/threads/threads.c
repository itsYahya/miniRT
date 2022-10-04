/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:54:48 by mzarhou           #+#    #+#             */
/*   Updated: 2022/10/03 17:21:34 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_threads.h"
#include "miniRT.h"

void	set_err(int value)
{
	*ft_errno() = value;
}

void	ft_init_thread(int index, int step, t__data *data, t_thread *thread)
{
	thread->begin = step * index;
	thread->end = step * (index + 1);
	thread->data = data;
}

void	ft_threads_lunsher(t__data *data)
{
	t_thread	ths[THREADS_NUM];
	int			index;
	t_vcamera	vcamera;
	int			step;

	index = 0;
	vcamera = ft_setup_camera(data->camera);
	step = HEIGHT / THREADS_NUM;
	while (index < THREADS_NUM && *ft_errno() == 0)
	{
		ths[index].vcamera = vcamera;
		ft_init_thread(index, step, data, ths + index);
		if (index == THREADS_NUM - 1)
			ths[index].end = HEIGHT;
		set_err(pthread_create(&ths[index].thread, NULL, render, &ths[index]));
		index++;
	}
	index = 0;
	while (index < THREADS_NUM && *ft_errno() == 0)
		set_err(pthread_join(ths[index++].thread, NULL));
	if (*ft_errno())
		return ;
	setup_mlxevents(data);
	ft_show_canvas(data->canvas);
	mlx_loop(data->canvas.mlx_ptr);
}
