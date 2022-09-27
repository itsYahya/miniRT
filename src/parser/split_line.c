#include "assert.h"
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

static int		is_space(char c)
{
	return (
		c == ' '
		|| c == '\t'
		|| c == '\r'
		|| c == '\v'
		|| c == '\f'
		|| c == '\n'
	);
}

static char	*next_space(char *current)
{
	while (current)
	{
		if (is_space(*current) || *current == '\0')
			break ;
		current++;
	}
	return (current);
}

int		count_words(char *line)
{
	int	count;

	count = 0;
	while (line && *line)
	{
		if (! is_space(*line) && ++count)
			line = next_space(line);
		else
			line++;
	}
	return (count);
}

static void	save_words(char **words, char *line)
{
	int		i;
	char	*next;

	i = 0;
	while (line && *line)
	{
		if (is_space(*line))
		{
			line++;
			continue;
		}
		next = next_space(line);
		if (*next == '\0') {
			words[i++] = ft_strdup(line);
			break ;
		} else {
			*next = 0;
			words[i++] = ft_strdup(line);
			line = next + 1;
		}
	}
}

char	**split_line(char *line)
{
	char	**words;
	int		words_count;

	if (! line)
		return (NULL);
	line = ft_strdup(line);
	if (! line )
		return (NULL);
	words_count = count_words(line);
	words = (char **)malloc(sizeof(char *) * words_count + 1);
	if (! words)
		return (NULL);
	save_words(words, line);
	words[words_count] = NULL;
	line = ft_free(line);
	return (words);
}
