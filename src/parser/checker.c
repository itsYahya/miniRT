/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:06:17 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/08/24 23:07:13 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "mutils.h"
#include <stdio.h>


int	validatePath(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 3)
		return (1);
	len -= 3;
	if (ft_strncmp(".rt", path + len, 3))
		return (1);
	while (len-- > 1 && path[len] != '.' && path[len] != ' ')
		;
	return (path[len] == '.' || path[len] == ' ');
}