/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:49:20 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/10/03 15:49:43 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_utils.h"

t_object	lst_object(t_list	*lst)
{
	return (*(t_object *)lst->content);
}
