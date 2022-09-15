#include "lst_utils.h"

t_object	lst_object(t_list	*lst)
{
	return *(t_object *)lst->content;
}
