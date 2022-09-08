#ifndef PAIR_H
# define PAIR_H

typedef union u_pair t_pair;
union u_pair
{
	struct
	{
		int	x;
		int	y;
	};
	struct
	{
		int	i;
		int	j;
	};
	struct
	{
		int	width;
		int	height;
	};
};

#endif
