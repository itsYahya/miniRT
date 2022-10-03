/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:46:22 by mzarhou           #+#    #+#             */
/*   Updated: 2022/10/03 15:46:23 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_arr_free(char **arr)
{
	int	i;

	i = -1;
	while (arr && arr[++i])
		arr[i] = ft_free(arr[i]);
	arr = ft_free(arr);
	return (NULL);
}
