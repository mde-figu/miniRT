/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:06:06 by mde-figu          #+#    #+#             */
/*   Updated: 2021/05/16 16:58:08 by mde-figu         ###   ########.fr       */
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
