/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:48:41 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/10/03 15:48:42 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_lstclear(t_list **list, void (*del)(void *))
{
	t_list	*head;
	t_list	*temp;

	head = *list;
	while (head)
	{
		temp = head;
		head = head->next;
		ft_lstdelone(temp, del);
	}
	*list = 0;
}
