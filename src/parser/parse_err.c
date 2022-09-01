#include "mutils.h"
#include "parser.h"
#include <stdio.h>

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
	ptintf("miniRT parsr: invalid identifier\n");
	exit(1);
}