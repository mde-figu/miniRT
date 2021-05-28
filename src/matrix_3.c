/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 22:29:51 by mde-figu          #+#    #+#             */
/*   Updated: 2021/05/27 11:53:54 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/components.h"

t_matrix	submatrix(t_matrix a, int i, int j)
{
	t_matrix	b;
	int			l;
	int			m;
	int			ii;
	int			jj;

	b = matrix(a.dim - 1);
	l = -1;
	ii = 0;
	while (**l < a.dim)
	{
		m = -1;
		jj = 0;
		while (++m < a.dim)
		{
			if ((l != i) && (m != j))
			{
				b.element[ii][jj] = a.element[l][m];
				jj++;
			}
		}
		if ((l != i) && (m != j))
			ii++;
	}
	return (b);
}

double	minor(t_matrix a, int i, int j)
{
	t_matrix	b;
	double		d;

	b = submatrix(a, i, j);
	d = determinant(b);
	free_matrix(&b);
	return (d);
}

double	cofactor(t_matrix a, int i, int j)
{
	double	ret;

	ret = 0;
	ret = minor(a, i, j);
	if ((i + j) % 2 != 0)
		ret = -1 *ret;
	return (ret);
}

t_matrix	matrix_multi(t_matrix a, t_matrix b)
{
	t_matrix	ab;
	int			i;
	int			j;

	ab.dim = 4;
	ab = matrix(4);
	i = 0;
	while (i < a.dim)
	{
		j = 0;
		while (j < a.dim)
		{
			ab.element[i][j] = a.element[i][0] * b.element[0][j]
				+ a.element[i][1] * b.element[1][j] + a.element[i][2]
				* b.element[2][j] + a.element[i][3] * b.element[3][j];
			j++;
		}
		i++;
	}
	return (ab);
}

t_matrix	identity(void)
{
	t_matrix	a;

	a = matrix(4);
	write_matrix(&a, 0, 0, 1.0);
	write_matrix(&a, 0, 1, 0.0);
	write_matrix(&a, 0, 2, 0.0);
	write_matrix(&a, 0, 3, 0.0);
	write_matrix(&a, 1, 0, 0.0);
	write_matrix(&a, 1, 1, 1.0);
	write_matrix(&a, 1, 2, 0.0);
	write_matrix(&a, 1, 3, 0.0);
	write_matrix(&a, 2, 0, 0.0);
	write_matrix(&a, 2, 1, 0.0);
	write_matrix(&a, 2, 2, 1.0);
	write_matrix(&a, 2, 3, 0.0);
	write_matrix(&a, 3, 0, 0.0);
	write_matrix(&a, 3, 1, 0.0);
	write_matrix(&a, 3, 2, 0.0);
	write_matrix(&a, 3, 3, 1.0);
	return (a);
}
