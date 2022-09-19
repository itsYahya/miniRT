#include "_parser.h"

void	multiple_elm_exit(char *id)
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

void	failed_to_open_file(char *path)
{
	errno = 1;
	printf("miniRT parser: failed to open file: %s\n", path);
}
