/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_threads.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:54:46 by mzarhou           #+#    #+#             */
/*   Updated: 2022/10/03 16:20:23 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_THREADS_H
# define H_THREADS_H

# include "raytracer.h"
# include "mlx_events.h"
# include <pthread.h>

# define THREADS_NUM 200

typedef struct s_thread
{
	int			begin;
	int			end;
	t__data		*data;
	t_vcamera	vcamera;
	pthread_t	thread;
}	t_thread;

void	ft_threads_lunsher(t__data *data);
void	*render(void *thread);

#endif
