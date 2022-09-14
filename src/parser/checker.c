#include "parser_.h"

int	validatePath(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 3)
		return (1);
	len -= 3;
	if (ft_strncmp(".rt", path + len, 3))
		return (1);
	while (len-- > 1 && path[len] != '.' && path[len] != ' ')
		;
	return (path[len] == '.' || path[len] == ' ');
}
