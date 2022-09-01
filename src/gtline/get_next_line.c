#include "get_next_line.h"
#include "mutils.h"

char	*get_the_rest(char *table, int index, int *check)
{
	char	*rest;

	if (!table)
		return (0);
	if (table[index] == 0)
	{
		free(table);
		return (0);
	}
	rest = ft_strdup(table + index);
	free(table);
	if (!rest)
		*check = -42;
	return (rest);
}

char	*get_the_line(char *line, char *table, int *index, int *check)
{
	char		*tmp_line;
	size_t		len;

	*index = 0;
	*check = 0;
	len = ft_strlen(line);
	if (!table)
		return (0);
	while (table[*index] != '\0' && table[*index] != '\n')
		*index += 1;
	*check = (table[*index] == '\n');
	*index += *check;
	tmp_line = (char *)ft_calloc(*index + len + 1, sizeof(char));
	ft_strlcat(tmp_line, line, len + 1);
	ft_strlcat(tmp_line, table, len + *index + 1);
	if (line)
		free(line);
	return (tmp_line);
}

t_data	ft_free_data(t_data data)
{
	data.ko = 1;
	if (data.line)
		free(data.line);
	if (data.table)
		free(data.table);
	return (data);
}

t_data	ft_look_for_line(char *line, int *index, int fd, int check)
{
	t_data	data;

	data.line = line;
	data.table = 0;
	data.ko = 0;
	while (!check)
	{
		data.table = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!data.table)
			return (ft_free_data(data));
		*index = read(fd, data.table, BUFFER_SIZE);
		if (*index == 0)
			return (data);
		else if (*index < 0)
			return (ft_free_data(data));
		data.line = get_the_line(data.line, data.table, index, &check);
		if (!data.line)
			return (ft_free_data(data));
		if (!check)
			free(data.table);
	}
	return (data);
}

char	*get_next_line(int fd)
{
	static char	*reminder;
	char		*line;
	int			index;
	int			check;
	t_data		data;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	check = 0;
	line = get_the_line(0, reminder, &index, &check);
	reminder = get_the_rest(reminder, index, &check);
	if (check == -42)
		return (ft_free(line));
	if (check)
		return (line);
	data = ft_look_for_line(line, &index, fd, 0);
	if (data.ko)
		return (0);
	reminder = get_the_rest(data.table, index, &check);
	if (check == -42)
		return (ft_free(data.line));
	return (data.line);
}
