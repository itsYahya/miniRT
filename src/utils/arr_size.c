/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:46:16 by mzarhou           #+#    #+#             */
/*   Updated: 2022/10/03 15:46:17 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_arr_size(char **arr)
{
	int	size;

	size = 0;
	while (arr && *(arr++) && ++size)
		;
	return (size);
}
