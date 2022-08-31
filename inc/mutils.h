#ifndef MUTILS_H
#define MUTILS_H

int		ft_strlen(char *str);
int		ft_strncmp(char *s1, char *s2, int n);
void	ft_putstr_fd(char *str, int fd);
char	**ft_split(char const *str, char sep);
int		wordCount(char **table);
int		ft_atoi(const char *num);

#endif