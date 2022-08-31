#include "miniRT.h"

static int	ft_isdigit(int ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}

static int	looper(const char *num, int index)
{
	int	number;

	number = 0;
	while (ft_isdigit(num[index]))
		number = number * 10 + (num[index++] - '0');
	return (number);
}

static int	is_space(char ch)
{
	if (ch == '\n' || ch == '\t' || ch == '\r'
		|| ch == ' ' || ch == '\v' || ch == '\f')
		return (1);
	return (0);
}

int	ft_atoi(const char *num)
{
	int	index;
	int	sign;
	int	test;
	int	number;

	index = 0;
	test = 0;
	sign = 1;
	number = 0;
	while (is_space(num[index]) && num[index] != '\0')
		index++;
	while (num[index] == 45 || num[index] == 43)
	{
		if (num[index] == 45)
			sign = -1;
		if (test)
			return (0);
		test = 1;
		index++;
	}
	number = looper(num, index);
	return (number * sign);
}