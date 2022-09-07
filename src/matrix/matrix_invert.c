#include "matrix.h"
#include "pair.h"


typedef union u_matrix2 t_matrix2;
union u_matrix2
{
	struct
	{
		float	r0_c0;
		float	r0_c1;
		float	r1_c0;
		float	r1_c1;
	};
	float raw[2][2];
};

typedef union u_matrix3 t_matrix3;
union u_matrix3
{
	struct
	{
		float	r0_c0;
		float	r0_c1;
		float	r0_c2;

		float	r1_c0;
		float	r1_c1;
		float	r1_c2;

		float	r2_c0;
		float	r2_c1;
		float	r2_c2;
	};
	float raw[3][3];
};

t_matrix2	submatrix3(t_matrix3 m, uint8_t row, uint16_t col)
{
	t_matrix2	mt2;
	t_pair		mt2_index;
	t_pair		index;

	mt2_index.y = 0;
	index.y = -1;
	while (++index.y < 3)
	{
		if (index.y == row)
			continue;
		index.x = -1;
		mt2_index.x= -1;
		while (++index.x < 3)
		{
			if (index.x == col)
				continue;
			mt2.raw[mt2_index.y][++mt2_index.x] = m.raw[index.y][index.x];
		}
		mt2_index.y++;
	}
	return (mt2);
}

static float		deteminant2(t_matrix2 m)
{
	return (m.r0_c0 * m.r1_c1 - m.r1_c0 * m.r0_c1);
}

static float	minor3(t_matrix3 mtx, uint8_t i, uint8_t j)
{
	return	deteminant2(submatrix3(mtx, i, j));
}

static float	cofactor3(t_matrix3 m, uint8_t row, uint8_t col)
{
	if ((row + col) % 2 == 0)
		return minor3(m, row, col);
	return (-1 * minor3(m, row, col));
}

static t_matrix3	submatrix4(t_matrix m, uint8_t row, uint16_t col)
{
	t_matrix3	mt3;
	t_pair		mt3_index;
	t_pair		index;

	mt3_index.y = 0;
	index.y = -1;
	while (++index.y < 4)
	{
		if (index.y == row)
			continue;
		index.x = -1;
		mt3_index.x= -1;
		while (++index.x < 4)
		{
			if (index.x == col)
				continue;
			mt3.raw[mt3_index.y][++mt3_index.x] = m.raw[index.y][index.x];
		}
		mt3_index.y++;
	}
	return (mt3);
}

static float determinant3(t_matrix3 m)
{
	int		j;
	float	det;

	j = -1;
	det = 0;
	while (++j < 3)
		det += m.raw[0][j] * cofactor3(m, 0, j);
	return (det);
}

static float	minor(t_matrix mtx, uint8_t i, uint8_t j)
{
	return	determinant3(submatrix4(mtx, i, j));
}

static float	cofactor(t_matrix m, uint8_t row, uint8_t col)
{
	if ((row + col) % 2 == 0)
		return minor(m, row, col);
	return (-1 * minor(m, row, col));
}

static float	determinant(t_matrix mtx)
{
	int		j;
	float	det;

	j = -1;
	det = 0;
	while (++j < 4)
		det += mtx.raw[0][j] * cofactor(mtx, 0, j);
	return (det);
}

bool	is_invertible(t_matrix mt)
{
	return (determinant(mt) != 0.0f);
}

t_matrix	inverse(t_matrix mtx)
{
	float		det;
	int			i;
	int			j;
	t_matrix	result;

	det = determinant(mtx);
	if (det == 0)
		return (mtx);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			result.raw[i][j] = cofactor(mtx, j, i) / det;
	}
	return (result);
}
