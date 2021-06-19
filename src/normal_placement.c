/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_placement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:40:31 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/18 22:11:30 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

t_tuple normal_placement(t_object o, t_tuple point)
{
	t_tuple		normal;
	double		dist;

	if (ft_memcmp(o.type, "sphere", 7) == 0)
		normal = subtract_tuple(point, create_tuple(0, 0, 0, 1));
	else if (ft_memcmp(o.type, "plane", 5) == 0)
		normal = create_tuple(0, 1, 0, 0);
	else if (ft_memcmp(o.type, "square", 7) == 0)
		normal = create_tuple(0, 1, 0, 0);
	else if (ft_memcmp(o.type, "triangle", 9) == 0)
		normal = o.normal;
	else if (ft_memcmp(o.type, "cylinder", 9) == 0)
	{
		dist = point.x * point.x + point.z * point.z;
		if (dist < 1 && point.y >= o.maximum - EPSILON)
			normal = create_tuple(0, 1, 0, 0);
		else if (dist < 1 && point.y <= o.minimum + EPSILON)
			normal = create_tuple(0, -1, 0, 0);
		else
			normal = create_tuple(point.x, 0, point.z, 0);
	}
	else
		normal = create_tuple(0, 0, 0, 0);
	return (normal);
}

t_tuple	place_normal(t_object o, t_tuple v)
{
	t_tuple		object_point;
	t_tuple		object_normal;
	t_tuple		world_normal;
	t_matrix	m1;
	t_matrix	m2;

	if (o.id == 2)
		world_normal.w = 0;
	m1 = inverse(o.transform);
	object_point = matrix_x_vector(m1, v);
	object_normal = normal_placement(o, object_point);
	m2 = transpose(m1);
	world_normal = matrix_x_vector(m2, object_normal);
	world_normal.w = 0;
	free_matrix(&m1);
	free_matrix(&m2);
	return (tuple_normalize(world_normal));
}
