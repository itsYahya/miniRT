/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:45:48 by mzarhou           #+#    #+#             */
/*   Updated: 2022/10/03 15:45:49 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

float	ft_max(float a, float b)
{
	if (a < b)
		return (b);
	return (a);
}

float	ft_min(float a, float b)
{
	if (a < b)
		return (a);
	return (b);
}
