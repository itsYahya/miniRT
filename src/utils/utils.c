
#include <unistd.h>

int	ft_strlen(const char *str)
{
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
	write(fd, str, ft_strlen(str));
}

int	ft_strncmp(const char *s1, const char *s2, int n)
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

int	ft_strcmp(const char *s1, const char *s2)
{
	int	length;

	length = ft_strlen(s1);
	if (length < ft_strlen(s2))
		length = ft_strlen(s2);
	return ft_strncmp(s1, s2, length);
}


int	wordCount(char **table)
{
	int	i;

	i = 0;
	while (table[i])
		i++;
	return (i);
}
