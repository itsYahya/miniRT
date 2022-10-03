/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:33:41 by mzarhou           #+#    #+#             */
/*   Updated: 2022/10/03 17:16:26 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_.h"
#include "raytracer.h"
#include "miniRT.h"
#include <signal.h>
#include "h_threads.h"

int	main(int argc, char **argv)
{
	t__data	data;

	init(&data);
	if (argc != 2)
		return (1);
	parser(argv[1], &data);
	if (*ft_errno() == 0)
	{
		ft_canvas(&data.canvas, WIDTH, HEIGHT);
		ft_threads_lunsher(&data);
	}
	ft_destroy(&data);
}
