#include "get_next_line.h"

char	*ft_strlcat(char *dest, char *src, int stop)
{
	int	index;
	int	len;

	if (src && dest)
	{
		index = 0;
		len = ft_strlen(dest);
		while (src[index] && (index + len) < stop - 1)
		{
			dest[index + len] = src[index];
			index++;
		}
		dest[index + len] = '\0';
	}
	return (dest);
}

char	*ft_strdup(char *str)
{
	char	*dest;
	int		index;

	index = 0;
	dest = (char *)ft_calloc(sizeof(char), ft_strlen(str) + 1);
	if (!dest)
		return (0);
	while (str[index] != '\0')
	{
		dest[index] = str[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*table;
	size_t	n;
	char	*str;

	table = (void *)malloc(count * size);
	if (table == NULL)
		return (0);
	n = size * count;
	str = (char *)table;
	if (n > 0)
	{
		while (n-- > 0)
			*str++ = (unsigned char)0;
	}
	return (table);
}
