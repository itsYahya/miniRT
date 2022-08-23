/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:49:18 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/08/23 17:55:54 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <unistd.h>

static int	ft_strlen(char *str){
	int	index;

	if (!str)
		return (0);
	index = 0;
	while (str[index])
		index++;
	return (index);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	index;

	index = 0;
	write(fd, str, ft_strlen(str));
}
