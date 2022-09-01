#include "mutils.h"

void	chomp(char *s, char c)
{
	int	len;

	len = ft_strlen(s);
	if (len == 0)
		return ;
	if (s[len - 1] == c)
		s[len - 1] = '\0';
}
