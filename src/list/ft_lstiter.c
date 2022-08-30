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
