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

typedef union u_fpair t_fpair;
union u_fpair
{
	struct
	{
		double	_0;
		double	_1;
	};
	struct
	{
		double	x;
		double	y;
	};
	struct
	{
		double	i;
		double	j;
	};
	struct
	{
		double	width;
		double	height;
	};
};

#endif
