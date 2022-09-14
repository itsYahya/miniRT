#include "parser_.h"

void	multiple_elm_exit(char *id)
{
	printf("%s: this identifier can only be declared once\n", id);
	exit(1);
}

void	invalid_argements(char *element)
{
	printf("%s parser: invalid number of arguments\n", element);
	exit(1);
}

void	invalid_identifier()
{
	printf("miniRT parsr: invalid identifier\n");
	exit(1);
}
