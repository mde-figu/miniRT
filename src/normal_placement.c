/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_placement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:40:31 by mde-figu          #+#    #+#             */
/*   Updated: 2021/05/31 14:04:02 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/components.h"

static t_tuple  

t_tuple normal_placement(t_object o, t_tuple point)
{
	t_tuple		normal;
	double		dist;

	if (ft_memcmp(o.type, "sphere", 7) == 0)
		normal = subtract_tuple(point, create_point(0, 0, 0));
	else if (ft_memcmp(o.type, "plane", 5) == 0)
		normal = create_vector(0, 1, 0);
	else if (ft_memcmp(o.type, "square", 7) == 0)
		normal = create_vector(0, 1, 0);
	else if (ft_memcmp(o.type, "triangle", 9) == 0)
		normal = o.normal;
	else if (ft_memcmp(o.type, "cylinder", 9) == 0)
	{
		dist = point.x * point.x + point.z * point.z;
		if (dist < 1 && point.y >= cyl.maximum - EPSILON)
			normal = create_vector(0, 1, 0);
		else if (dist < 1 && point.y <= cyl.minimun + EPSILON)
			normal = create_vector(0, -1, 0);
		else
			normal = create_vector(point.x, 0, point.z);
	}
	else
		normal = create_vector(0, 0, 0);
	return (normal);
}
