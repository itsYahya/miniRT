#include <errno.h>
#include "utils.h"
#include <limits.h>
#include <stdio.h>
#include <math.h>

static void	ft_remove_trailing_zeros(char *s)
{
	int		len;

	len = ft_strlen(s);
	if (len == 0)
		return ;
	while (len > 0 && s[len - 1] == '0')
	{
		chomp(s, '0');
		len--;
	}
	if (ft_strlen(s) == 0)
		s[0] = '0';
}

double	ft_stod(const char *s)
{
	char	**parts;
	int		part1;
	int		part2;
	int		part2_len;
	int		sign;

	if (! s || ! is_double(s))
		return (errno = 1, 0.0);
	sign = 1;
	if (s && *s == '-' && s++)
		sign = -1;
	else if (s && *s == '+')
		s++;
	parts = ft_split(s, '.');
	ft_remove_trailing_zeros(parts[1]);
	part2_len = ft_strlen(parts[1]);
	if (ft_strlen(parts[0]) > 9 || part2_len > 6)
		return (ft_arr_free(parts), errno = 1, 0.0);
	part1 = ft_atoi(parts[0]);
	if (part2_len == 0)
	{
		part2 = 0;
		part2_len = 1;
	} else
		part2 = ft_atoi(parts[1]);
	return (ft_arr_free(parts), sign * ((long double)part1 + part2 / pow(10, part2_len)));
}
