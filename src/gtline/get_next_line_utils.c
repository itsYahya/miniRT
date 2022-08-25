/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:47:51 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/08/24 22:08:45 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strlcat(char *dest, char *src, int stop)
{
	int	index;
	int	len;

	if (src && dest)
	{
		index = 0;
		len = ft_strlen(dest);
		while (src[index] && (index + len) < stop - 1)
		{
			dest[index + len] = src[index];
			index++;
		}
		dest[index + len] = '\0';
	}
	return (dest);
}

char	*ft_strdup(char *str)
{
	char	*dest;
	int		index;

	index = 0;
	dest = (char *)ft_calloc(sizeof(char), ft_strlen(str) + 1);
	if (!dest)
		return (0);
	while (str[index] != '\0')
	{
		dest[index] = str[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

char	*ft_free(char *line)
{
	if (line)
		free(line);
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*table;
	size_t	n;
	char	*str;

	table = (void *)malloc(count * size);
	if (table == NULL)
		return (0);
	n = size * count;
	str = (char *)table;
	if (n > 0)
	{
		while (n-- > 0)
			*str++ = (unsigned char)0;
	}
	return (table);
}
