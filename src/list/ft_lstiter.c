/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:48:46 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/10/03 15:48:47 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_lstiter(t_list *node, void (*f)(void *))
{
	t_list	*head;

	head = node;
	while (head)
	{
		(*f)(head->content);
		head = head->next;
	}
}
