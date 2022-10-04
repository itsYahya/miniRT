/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:22:33 by mzarhou           #+#    #+#             */
/*   Updated: 2022/10/03 17:22:41 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_H
# define PAIR_H

typedef union u_pair	t_pair;
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

typedef union u_fpair	t_fpair;
union u_fpair
{
	struct
	{
		float	_0;
		float	_1;
	};
	struct
	{
		float	x;
		float	y;
	};
	struct
	{
		float	i;
		float	j;
	};
	struct
	{
		float	width;
		float	height;
	};
};

#endif
