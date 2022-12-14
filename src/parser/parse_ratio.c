/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ratio.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:29:22 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/10/03 17:15:21 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_.h"

static void	print_error(void)
{
	*ft_errno() = 1;
	printf("Ratio parser: invalid input\n");
}

float	get_ratio(const char *token)
{
	float	ratio;

	ratio = ft_stod(token);
	if (ratio > 1 || ratio < 0)
		print_error();
	return (ratio);
}
