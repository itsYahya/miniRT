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
