#include "miniRT.h"
#include "get_next_line.h"
#include "mutils.h"
#include <fcntl.h>
#include "parser.h"
#include "matrix.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	// t__data	data;

	// data.objects = NULL;
	// if (argc != 2)
	// 	return (ft_putstr_fd("invalid argumanet\n", 2), 1);
	// if (parser(argv[1], &data) != 0)
	// 	exit(1);
	// t_list *lst = data.objects;
	// while (lst) {
	// 	printf("%c - ", lst->type);
	// 	lst = lst->next;
	// }
	// printf("\n");
	// ft_lstclear(&data.objects, free);

	// t_matrix m = {{
	// 	-5 , 2 , 6 , -8 ,
	// 	1 , -5 , 1 , 8 ,
	// 	7 , 7 , -6 , -7 ,
	// 	1 , -3 , 7 , 4
	// }};
	// t_matrix m = {{
	// 	8 , -5 , 9 , 2 ,
	// 	7 , 5 , 6 , 1 ,
	// 	-6 , 0 , 9 , 6 ,
	// 	-3 , 0 , -9 , -4
	// }};
	// t_matrix m = {{
	// 	9 , 3 , 0 , 9 ,
	// 	-5 , -2 , -6 , -3 ,
	// 	-4 , 9 , 6 , 4 ,
	// 	-7 , 6 , 6 , 2
	// }};

	// print_matrix(inverse(m));


	t_matrix A = {{
		3 , -9 , 7 , 3 ,
		3 , -8 , 2 , -9 ,
		-4 , 4 , 4 , 1 ,
		-6 , 5 , -1 , 1
	}};
	t_matrix B = {{
		8 , 2 , 2 , 2 ,
		3 , -1 , 7 , 0 ,
		7 , 0 , 5 , 4 ,
		6 , -2 , 0 , 5
	}};
	t_matrix C = matrix_multiply(A, B);
	if (matrix_equal(A, matrix_multiply(C, inverse(B))))
		printf("yes");
	else
		printf("no");
	printf("\n");

	return (0);
}
