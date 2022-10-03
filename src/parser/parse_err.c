/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:27:37 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/10/03 17:15:21 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_.h"

void	multiple_elm(char *id)
{
	*ft_errno() = 1;
	printf("%s: this identifier can only be declared once\n", id);
}

void	invalid_argements(char *element)
{
	*ft_errno() = 1;
	printf("%s parser: invalid number of arguments\n", element);
}

void	invalid_identifier(char *id)
{
	*ft_errno() = 1;
	printf("parser: invalid identifier %s\n", id);
}

void	invalid_file(void)
{
	*ft_errno() = 1;
	ft_putstr_fd("invalid file\n", 2);
}
