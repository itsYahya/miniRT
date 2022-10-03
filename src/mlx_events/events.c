/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:08:44 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/10/03 16:09:44 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_.h"
#include <stdio.h>
#include <stdlib.h>
#include "canvas.h"
#include "miniRT.h"

static int	on_close(void *data)
{
	ft_destroy(data);
	return (exit(0), 0);
}

void	setup_mlxevents(t__data *data)
{
	if (! data || ! data->canvas.mlx_win)
	{
		printf("failed to setup mlx events\n");
		return ;
	}
	mlx_hook(data->canvas.mlx_win, 17, 0, on_close, data);
}
