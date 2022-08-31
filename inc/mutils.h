#ifndef MUTILS_H
#define MUTILS_H

int		ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, int n);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr_fd(char *str, int fd);
char	**ft_split(char const *str, char sep);
int		wordCount(char **table);
int		ft_atoi(const char *num);

#endif
