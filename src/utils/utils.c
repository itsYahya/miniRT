#include "miniRT.h"
#include <unistd.h>

int	ft_strlen(char *str){
	int	index;

	if (!str)
		return (0);
	index = 0;
	while (str[index])
		index++;
	return (index);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	index;

	index = 0;
	write(fd, str, ft_strlen(str));
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	if (n == -1)
		n = ft_strlen(s2);
	if (n < 1)
		return (0);
	i = 0;
	while (s1[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
