/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:45:41 by mzarhou           #+#    #+#             */
/*   Updated: 2022/10/03 15:45:42 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "utils.h"

static int	ft_word_length(const char *str, int i, char sep)
{
	int	word_length;

	word_length = 0;
	while (str && str[i] && str[i] != sep)
	{
		word_length++;
		i++;
	}
	return (word_length);
}

static int	ft_get_words_nb(const char *str, char sep)
{
	int	new_word;
	int	count;

	new_word = 0;
	count = 0;
	while (str && *str)
	{
		if (*str == sep)
			new_word = 0;
		else if (new_word == 0)
		{
			new_word = 1;
			count++;
		}
		str++;
	}
	return (count);
}

static void	*free_memory(char **words, int end_index)
{
	int	i;

	i = 0;
	if (!words)
		return (0);
	while (i < end_index && words[i])
		free(words[i]);
	free(words);
	return (0);
}

static void	ft_skip(const char *str, int *i, char sep)
{
	if (!str || !i)
		return ;
	while (str[*i] == sep)
		(*i)++;
}

char	**ft_split(char const *str, char sep)
{
	char	**words;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!str)
		return (0);
	words = (char **)malloc(sizeof(char *) * ft_get_words_nb(str, sep) + 1);
	if (!words)
		return (0);
	while (str[i] && j < ft_get_words_nb(str, sep))
	{
		k = 0;
		ft_skip(str, &i, sep);
		words[j] = (char *)malloc(ft_word_length(str, i, sep) + 1);
		if (!words[j])
			return (free_memory(words, j));
		while (str[i] != sep && str[i])
			words[j][k++] = str[i++];
		words[j++][k] = '\0';
	}
	words[j] = 0;
	return (words);
}
