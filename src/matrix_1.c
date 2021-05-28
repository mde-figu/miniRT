/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:06:06 by mde-figu          #+#    #+#             */
/*   Updated: 2021/05/27 11:39:01 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/components.h"

t_matrix	matrix(int dim)
{
	t_matrix	m;
	int			i;

	m.dim = dim;
	m.element = (double **)malloc(sizeof(double *) * dim);
	i = 0;
	while (i < dim)
	{
		m.element[i] = (double *)malloc(sizeof(double) * dim);
		i++;
	}
	return (m);
}

t_tuple	matrix_x_vector(t_matrix a, t_tuple b)
{
	t_tuple	c;
	c.x = a.element[0][0] * b.x + a.element[0][1] * b.y
		+ a.element[0][2] * b.z + a.element[0][3] * b.w;
	c.y = a.element[1][0] * b.x + a.element[1][1] * b.y
		+ a.element[1][2] * b.z + a.element[1][3] * b.w;
	c.z = a.element[2][0] * b.x + a.element[2][1] * b.y
		+ a.element[2][2] * b.z + a.element[2][3] * b.w;
	c.w = a.element[3][0] * b.x + a.element[3][1] * b.y
		+ a.element[3][2] * b.z + a.element[3][3] * b.w;
	return (c);
}

void	write_matrix(t_matrix *m, int i, int j, double e)
{
	m->element[i][j] = e;
}

void	copy_matrix(t_matrix *d, t_matrix o)
{
	int	i;
	int	j;

	i = 0;
	while (i < o.dim)
	{
		j = 0;
		while (j < o.dim)
		{
			write_matrix(d, i, j, o.element[i][j]);
			j++;
		}
		i++;
	}

}

void	free_matrix(t_matrix *a)
{
	int	i;

	i = 0;
	while (i < a->dim)
	{
		free(a->element[i]);
		i++;
	}
	free(a->element);
}
