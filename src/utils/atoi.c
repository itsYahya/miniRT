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

typedef struct s_data_atoi
{
	int	index;
	int	sign;
	int	test;
	int	number;
}	t_atoi_d;

static void	ft_init(t_atoi_d *data)
{
	data->index = 0;
	data->test = 0;
	data->sign = 1;
	data->number = 0;
}

int	ft_atoi(const char *num)
{
	t_atoi_d	data;

	if (!num)
		return (0);
	ft_init(&data);
	while (is_space(num[data.index]) && num[data.index] != '\0')
		data.index++;
	while (num[data.index] == 45 || num[data.index] == 43)
	{
		if (num[data.index] == 45)
			data.sign = -1;
		if (data.test)
			return (0);
		data.test = 1;
		data.index++;
	}
	data.number = looper(num, data.index);
	return (data.number * data.sign);
}