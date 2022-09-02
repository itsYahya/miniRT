#include <stdlib.h>
#include "list.h"

t_list	*ft_lstnew(void *content, t_type type)
{
	t_list	*head;

	head = (t_list *)malloc(sizeof(t_list));
	if (!head || !content)
		return (0);
	head->content = content;
	head->type = type;
	head->next = 0;
	return (head);
}
