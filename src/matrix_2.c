/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:13:09 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/06 20:50:36 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

t_matrix	translation(double x, double y, double z)
{
	t_matrix	a;

	a = matrix(4);
	write_matrix(&a, 0, 0, 1.0);
	write_matrix(&a, 0, 1, 0.0);
	write_matrix(&a, 0, 2, 0.0);
	write_matrix(&a, 0, 3, x);
	write_matrix(&a, 1, 0, 0.0);
	write_matrix(&a, 1, 1, 1.0);
	write_matrix(&a, 1, 2, 0.0);
	write_matrix(&a, 1, 3, y);
	write_matrix(&a, 2, 0, 0.0);
	write_matrix(&a, 2, 1, 0.0);
	write_matrix(&a, 2, 2, 1.0);
	write_matrix(&a, 2, 3, z);
	write_matrix(&a, 3, 0, 0.0);
	write_matrix(&a, 3, 1, 0.0);
	write_matrix(&a, 3, 2, 0.0);
	write_matrix(&a, 3, 3, 1.0);
	return (a);
}

t_matrix	scaling(double x, double y, double z)
{
	t_matrix	a;

		a = matrix(4);
	write_matrix(&a, 0, 0, x);
	write_matrix(&a, 0, 1, 0.0);
	write_matrix(&a, 0, 2, 0.0);
	write_matrix(&a, 0, 3, 0.0);
	write_matrix(&a, 1, 0, 0.0);
	write_matrix(&a, 1, 1, y);
	write_matrix(&a, 1, 2, 0.0);
	write_matrix(&a, 1, 3, 0.0);
	write_matrix(&a, 2, 0, 0.0);
	write_matrix(&a, 2, 1, 0.0);
	write_matrix(&a, 2, 2, z);
	write_matrix(&a, 2, 3, 0.0);
	write_matrix(&a, 3, 0, 0.0);
	write_matrix(&a, 3, 1, 0.0);
	write_matrix(&a, 3, 2, 0.0);
	write_matrix(&a, 3, 3, 1.0);
}

double	cofactor(t_matrix a, int i, int j)
{
	double	ret;

	ret = 0;
	ret = matrix_minor(a, i, j);
	if ((i + j) % 2 != 0)
		ret = -1 * ret;
	return (ret);
}

t_matrix	inverse(t_matrix a)
{
	t_matrix	b;
	t_coord		p;
	double		c;
	double		d;

	d = determinant(a);
	c = 0;
	b = matrix(a.dim)
	if (!check_invert(a))
		return (b);
	else
	{
		p.i = -1;
		while (++(p.1) < a.dim)
		{
			p.j = -1;
			while (++(p.j) < a.dim)
			{
				c = matrix_minor(a, p.i, p.j);
				b.element[p.j][p.i] = c / d;
			}
		}
		return (b);
	}
}

double	determinant(t_matrix a)
{
	double	ret;
	int		i;

	ret = 0;
	if (a.dim == 2)
	{
		ret = a.element[0][0] * a.element[1][1]
			- a.element[0][1] * a.element[1][0];
	}
	else
	{
		i = 0;
		while (i < a.dim)
		{
			resp = resp + a.element[0][i] * cofactor(a, 0, i);
			i++;
		}
		return (ret);
	}
}
