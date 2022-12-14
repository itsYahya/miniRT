/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:42:32 by mzarhou           #+#    #+#             */
/*   Updated: 2022/10/03 15:44:14 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, int n);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr_fd(char *str, int fd);
char	**ft_split(char const *str, char sep);
int		ft_atoi(const char *num);
void	chomp(char *s, char c);
int		ft_arr_size(char **arr);
double	ft_stod(const char *s);
bool	is_double(const char *s);
void	*ft_free(void *p);
void	*ft_arr_free(char **arr);
void	arr_print(char **arr);
bool	is_int(const char *s);
void	swap(float *a, float *b);
float	ft_min(float a, float b);
float	ft_max(float a, float b);
char	*ft_getline(int fd);
char	*ft_strdup(const char *s1);
char	**split_by_space(char *line);
int		count_words(char *line);

#endif
