/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:27:37 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/10/03 16:27:38 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_.h"

void	multiple_elm(char *id)
{
	errno = 1;
	printf("%s: this identifier can only be declared once\n", id);
}

void	invalid_argements(char *element)
{
	errno = 1;
	printf("%s parser: invalid number of arguments\n", element);
}

void	invalid_identifier(char *id)
{
	errno = 1;
	printf("parser: invalid identifier %s\n", id);
}

void	invalid_file(void)
{
	errno = 1;
	ft_putstr_fd("invalid file\n", 2);
}
