/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:43:18 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/24 19:46:48 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

double	tuple_mag(t_tuple t1)
{
	double	magnitude;
	double	tmp;

	if (t1.w != 1 && t1.w != 0)
		error_list(9);
	tmp = t1.x * t1.x + t1.y * t1.y + t1.z * t1.z + t1.w * t1.w;
	magnitude = sqrt(tmp);
	return (magnitude);
}

double	tuple_rsqrt(t_tuple t1)
{
	long		i;
	float		x2;
	float		y;
	double		number;
	const float	threehalfs = 1.5F;

	number = t1.x * t1.x + t1.y * t1.y + t1.z * t1.z + t1.w * t1.w;
	x2 = number * 0.5F;
	y = number;
	i = *(long *) &y;
	i = 0x5f3759df - (i >> 1);
	y = *(float *) &i;
	y = y * (threehalfs - (x2 * y * y));
	y = y * (threehalfs - (x2 * y * y));
	return ((double)y);
}

t_tuple	tuple_normalize(t_tuple t1)
{
	double	magnitude;

	magnitude = tuple_mag(t1);
	t1.x = t1.x / magnitude;
	t1.y = t1.y / magnitude;
	t1.z = t1.z / magnitude;
	t1.w = t1.w / magnitude;
	return (t1);
}

t_tuple	quake_normalize(t_tuple t1)
{
	double	magnitude;

	magnitude = tuple_rsqrt(t1);
	t1.x = t1.x * magnitude;
	t1.y = t1.y * magnitude;
	t1.z = t1.z * magnitude;
	t1.w = t1.w * magnitude;
	return (t1);
}

t_tuple	cross_product(t_tuple t1, t_tuple t2)
{
	t_tuple	new;

	new.x = (t1.y * t2.z) - (t1.z * t2.y);
	new.y = (t1.z * t2.x) - (t1.x * t2.z);
	new.z = (t1.x * t2.y) - (t1.y * t2.x);
	new.w = 0;
	return (new);
}
