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
