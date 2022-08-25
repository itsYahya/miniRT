/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:55:19 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/08/24 22:32:26 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "get_next_line.h"
#include "mutils.h"
#include <fcntl.h>
#include "parser.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (ft_putstr_fd("invalid argumanet\n", 2), 1);
	parser(argv[1]);
	return (0);
}
