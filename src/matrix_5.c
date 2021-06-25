/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:34:01 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/25 17:06:56 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

static void	init(double *v, double *v1, double *v2, t_tuple normal)
{
	double	angle;

	angle = acos(dot_product(normal, create_tuple(0, 1, 0, 0)));
	*v = cos(angle);
	*v1 = sin(angle);
	*v2 = 1.0 - *v;
}

t_matrix	rotate(t_tuple normal)
{
	t_matrix	a;
	double		vals[3];
	t_tuple		axis;

	a = matrix(4);
	axis = cross_product(normal, create_tuple(0, 1, 0, 0));
	init(&vals[0], &vals[1], &vals[2], normal);
	write_matrix(&a, 0, 0, vals[0] + (ft_pow(axis.x, 2) * vals[2]));
	write_matrix(&a, 0, 1, (axis.x * axis.y * vals[2]) - (axis.z * vals[1]));
	write_matrix(&a, 0, 2, (axis.x * axis.z * vals[2]) + (axis.y * vals[1]));
	write_matrix(&a, 0, 3, 0.0);
	write_matrix(&a, 1, 0, (axis.y * axis.z * vals[2]) + (axis.z * vals[1]));
	write_matrix(&a, 1, 1, vals[0] + (ft_pow(axis.y, 2) * vals[2]));
	write_matrix(&a, 1, 2, (axis.y * axis.z * vals[2]) - (axis.x * vals[1]));
	write_matrix(&a, 1, 3, 0.0);
	write_matrix(&a, 2, 0, (axis.z * axis.x * vals[2]) - (axis.y * vals[1]));
	write_matrix(&a, 2, 1, (axis.z * axis.y * vals[2]) + (axis.x * vals[1]));
	write_matrix(&a, 2, 2, vals[0] + (ft_pow(axis.z, 2) * vals[2]));
	write_matrix(&a, 2, 3, 0.0);
	write_matrix(&a, 3, 0, 0.0);
	write_matrix(&a, 3, 1, 0.0);
	write_matrix(&a, 3, 2, 0.0);
	write_matrix(&a, 3, 3, 1.0);
	return (a);
}

t_matrix	transpose(t_matrix a)
{
	t_matrix	at;
	int			i;
	int			j;

	at = matrix(4);
	i = 0;
	while (i < a.dim)
	{
		j = 0;
		while (j < a.dim)
		{
			at.element[j][i] = a.element[i][j];
			j++;
		}
		i++;
	}
	return (at);
}
