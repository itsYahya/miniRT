#include "parser_.h"

void	multiple_elm(char *id)
{
	errno = 1;
	printf("%s: this identifier can only be declared once\n", id);
}

void	invalid_argements(char *element)
{
	errno = 1;
	printf("%s parser: invalid number of arguments\n", element);
}

void	invalid_identifier()
{
	errno = 1;
	printf("miniRT parsr: invalid identifier\n");
}

void	invalid_file()
{
	errno = 1;
	ft_putstr_fd("invalid file\n", 2);
}
