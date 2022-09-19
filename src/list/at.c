#include "list.h"
#include <stdlib.h>
#include <stdio.h>

t_list	*at(t_list *lst, int index)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (i == index)
			return (lst);
		lst = lst->next;
		i++;
	}
	printf("index out of range [at]\n");
	return (NULL);
}
