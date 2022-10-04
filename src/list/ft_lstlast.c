/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:48:49 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/10/03 15:48:50 by yel-mrab         ###   ########.fr       */
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
