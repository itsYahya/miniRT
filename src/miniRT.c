/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:33:11 by mzarhou           #+#    #+#             */
/*   Updated: 2022/10/03 17:15:21 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <stdlib.h>
#include "canvas.h"

int	*ft_errno(void)
{
	static int	err = 0;

	return (&err);
}

void	init(t__data *data)
{
	*ft_errno() = 0;
	data->objects = NULL;
	data->lights = NULL;
	data->canvas.img = NULL;
	data->canvas.img_data = NULL;
	data->canvas.mlx_ptr = NULL;
	data->canvas.mlx_win = NULL;
}

void	ft_destroy(t__data *data)
{
	printf("destroying data\n");
	if (! data)
		return ;
	ft_lstclear(&data->objects, free);
	ft_lstclear(&data->lights, free);
	destroy_canvas(data->canvas);
}
