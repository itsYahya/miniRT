#include "miniRT.h"
#include "get_next_line.h"
#include "mutils.h"
#include <fcntl.h>
#include "parser.h"
#include "tuple.h"
#include <errno.h>
#include "canvas.h"

int	main(int argc, char **argv)
{
	t__data	data;

	data.objects = NULL;
	errno = 0;
	if (argc != 2)
		return (ft_putstr_fd("invalid argumanet\n", 2), 1);
	if (parser(argv[1], &data) != 0)
		exit(1);
	t_list *lst = data.objects;
	while (lst) {
		printf("%c - ", lst->type);
		lst = lst->next;
	}
	printf("\n");
	ft_lstclear(&data.objects, free);
	renderer();
	return (0);
}
