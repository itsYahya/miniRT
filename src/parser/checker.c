/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:11:13 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/10/03 16:11:35 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_.h"

int	validate_path(char *path)
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
