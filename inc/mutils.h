#ifndef MUTILS_H
# define MUTILS_H

# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include "sceneMaterial.h"

int		ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, int n);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr_fd(char *str, int fd);
char	**ft_split(char const *str, char sep);
int		wordCount(char **table);
int		ft_atoi(const char *num);
void	chomp(char *s, char c);
int		ft_arr_size(char **arr);
double	ft_stod(const char *s);
bool	is_double(const char *s);
void	*ft_free(void *p);
void	*ft_arr_free(char **arr);
void	arr_print(char **arr);
bool	is_int(const char *s);

#endif
