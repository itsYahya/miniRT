#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_data
{
	char	*table;
	char	*line;
	int		ko;
}t_data;

int		ft_strlen(char *str);
char	*ft_strlcat(char *dest, char *src, int stop);
char	*ft_strdup(char *str);
void	*ft_calloc(size_t count, size_t size);
char	*get_next_line(int fd);
char	*get_the_line(char *line, char *table, int *index, int *check);
char	*get_the_rest(char *table, int index, int *check);
char	*ft_free(char *line);
t_data	ft_look_for_line(char *line, int *index, int fd, int check);
t_data	ft_free_data(t_data data);

#endif
