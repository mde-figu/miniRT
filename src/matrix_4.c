/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:13:35 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/06 20:19:32 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/components.h"

t_matrix	inverse(t_matrix a)
{
	t_matrix	b;
	t_coord		p;
	double		c;
	double		d;

	d = det(a);
	c = 0;
	b = matrix(a.dim);
	if (!is_invertible(a))
		return (error_list(57));
	p.i = -1;
	while (++(p.i) < a.dim)
	{
		p.j = -1;
		while (++(p.j) < a.dim)
		{
			c = cofactor(a, p.i, p.j);
			b.element[p.j][p.i] = c / d;
		}
	}
	return (b);
}

bool	is_invertible(t_matrix a)
{
	if (det(a) == 0)
		return (false);
	else
		return (true);
}

t_matrix	rotation_x(double r)
{
	t_matrix	a;

	a = matrix(4);
	write_matrix(&a, 0, 0, 1.0);
	write_matrix(&a, 0, 1, 0.0);
	write_matrix(&a, 0, 2, 0.0);
	write_matrix(&a, 0, 3, 0.0);
	write_matrix(&a, 1, 0, 0.0);
	write_matrix(&a, 1, 1, cos(r));
	write_matrix(&a, 1, 2, -sin(r));
	write_matrix(&a, 1, 3, 0.0);
	write_matrix(&a, 2, 0, 0.0);
	write_matrix(&a, 2, 1, sin(r));
	write_matrix(&a, 2, 2, cos(r));
	write_matrix(&a, 2, 3, 0.0);
	write_matrix(&a, 3, 0, 0.0);
	write_matrix(&a, 3, 1, 0.0);
	write_matrix(&a, 3, 2, 0.0);
	write_matrix(&a, 3, 3, 1.0);
	return (a);
}

t_matrix	rotation_y(double r)
{
	t_matrix	a;

	a = matrix(4);
	write_matrix(&a, 0, 0, cos(r));
	write_matrix(&a, 0, 1, 0.0);
	write_matrix(&a, 0, 2, sin(r));
	write_matrix(&a, 0, 3, 0.0);
	write_matrix(&a, 1, 0, 0.0);
	write_matrix(&a, 1, 1, 1.0);
	write_matrix(&a, 1, 2, 0.0);
	write_matrix(&a, 1, 3, 0.0);
	write_matrix(&a, 2, 0, -sin(r));
	write_matrix(&a, 2, 1, 0.0);
	write_matrix(&a, 2, 2, cos(r));
	write_matrix(&a, 2, 3, 0.0);
	write_matrix(&a, 3, 0, 0.0);
	write_matrix(&a, 3, 1, 0.0);
	write_matrix(&a, 3, 2, 0.0);
	write_matrix(&a, 3, 3, 1.0);
	return (a);
}

t_matrix	rotation_z(double r)
{
	t_matrix	a;

	a = matrix(4);
	write_matrix(&a, 0, 0, cos(r));
	write_matrix(&a, 0, 1, -sin(r));
	write_matrix(&a, 0, 2, 0.0);
	write_matrix(&a, 0, 3, 0.0);
	write_matrix(&a, 1, 0, sin(r));
	write_matrix(&a, 1, 1, cos(r));
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
