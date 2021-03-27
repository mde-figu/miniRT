/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:43:25 by mde-figu          #+#    #+#             */
/*   Updated: 2021/03/23 18:43:40 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "tuples.h"

t_tuple	create_tuple(double x, double y, double z, int w)
{
	t_tuple	tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = w;
	return (tuple);
}

t_tuple	add_tuple(t_tuple t1, t_tuple t2)
{
	t_tuple	new;

	if ((t1.w != 1 && t1.w != 0) || (t2.w != 1 && t2.w != 0))
	new.x = t1.x + t2.x;
	new.y = t1.y + t2.y;
	new.z = t1.z + t2.z;
	new.w = t1.w + t2.w;
	if (new.w != 1 && new.w != 0)
	return (new);
}

t_tuple	subtract_tuple(t_tuple t1, t_tuple t2)
{
	t_tuple	new;

	if ((t1.w != 1 && t1.w != 0) || (t2.w != 1 && t2.w != 0))
	new.x = t1.x - t2.x;
	new.y = t1.y - t2.y;
	new.z = t1.z - t2.z;
	new.w = t1.w - t2.w;
	if (new.w != 1 && new.w != 0)
	return (new);
}

t_tuple	negate_tuple(t_tuple t1)
{
	t_tuple	new;

	if (t1.w != 1 && t1.w != 0)
	new.x = t1.x * -1;
	new.y = t1.y * -1;
	new.z = t1.z * -1;
	new.w = t1.w * -1;
	if (new.w != 1 && new.w != -1)
	return (new);
}

t_tuple	scale_tuple(t_tuple t1, double scale)
{
	t_tuple	new;

	if (t1.w != 1 && t1.w != 0)
	new.x = t1.x * scale;
	new.y = t1.y * scale;
	new.z = t1.z * scale;
	new.w = t1.w * 1;
	return (new);
}
