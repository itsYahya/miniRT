#include "list.h"

void	ft_lstadd_front(t_list **list, t_list *new)
{
	t_list	*head;

	head = *list;
	new->next = head;
	*list = new;
}
