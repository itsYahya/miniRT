/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:44:57 by mzarhou           #+#    #+#             */
/*   Updated: 2022/10/03 15:44:58 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*res;
	int		len;
	int		i;

	len = ft_strlen(s1);
	res = (char *)malloc(len + 1);
	if (!res)
		return (0);
	i = 0;
	while (i < len)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = 0;
	return (res);
}
