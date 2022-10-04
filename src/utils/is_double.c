/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:45:54 by mzarhou           #+#    #+#             */
/*   Updated: 2022/10/03 16:24:01 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>

static bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

bool	is_int(const char *s)
{
	if (s && (*s == '+' || *s == '-'))
		s++;
	if (ft_strlen(s) == 0)
		return (false);
	while (s && *s)
	{
		if (! is_digit(*s))
			return (false);
		s++;
	}
	return (true);
}

bool	is_float(const char *s)
{
	int	len;
	int	i;
	int	dot_skiped;

	if (s && (*s == '+' || *s == '-'))
		s++;
	len = ft_strlen(s);
	dot_skiped = 0;
	if (len == 0)
		return (false);
	i = 0;
	while (s[i])
	{
		if (s[i] == '.' && dot_skiped == 0)
			dot_skiped = 1;
		else if (s[i] == 'f')
			break ;
		else if (! is_digit(s[i]))
			return (false);
		i++;
	}
	return (s[i] == 'f' && ((i + 1) == len));
}

bool	is_double(const char *s)
{
	char	**parts;
	int		size;
	bool	result;

	if (s && (*s == '+' || *s == '-'))
		s++;
	if (is_int(s) || is_float(s))
		return (true);
	parts = ft_split(s, '.');
	size = ft_arr_size(parts);
	result = (size == 2 && is_int(parts[0]) && is_int(parts[1]));
	return (ft_arr_free(parts), result);
}
