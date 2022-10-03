/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:48:59 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/10/03 15:49:00 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	ft_lstsize(t_list *head)
{
	int		index;
	t_list	*temp;

	index = 0;
	temp = head;
	while (temp)
	{
		index++;
		temp = temp->next;
	}
	return (index);
}
