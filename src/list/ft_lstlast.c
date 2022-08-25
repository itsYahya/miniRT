/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:00:12 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/08/25 19:50:53 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*ft_lstlast(t_list *head)
{
	t_list	*pre;

	pre = 0;
	while (head)
	{
		pre = head;
		head = head->next;
	}
	return (pre);
}
