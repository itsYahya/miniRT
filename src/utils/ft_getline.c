/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:45:57 by mzarhou           #+#    #+#             */
/*   Updated: 2022/10/03 15:45:58 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "get_next_line.h"

static int	ft_good_line(char *line)
{
	int	i;

	if (!line)
		return (1);
	i = 0;
	while (line[i] == ' ')
		i++;
	return (!(line[i] == 0 || line[i] == 10));
}

char	*ft_getline(int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (ft_good_line(line))
			return (line);
		free(line);
	}
}
