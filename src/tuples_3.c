/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:02:07 by mde-figu          #+#    #+#             */
/*   Updated: 2021/05/31 14:10:20 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/components.h"

t_tuple create_point(double x, double y, double z)
{
	t_tuple	p;

	p.x = x;
	p.y = y;
	p.z = z;
	p.w = 1;
	return (p);
}

t_tuple create_vector(double x, double y, double z)
{
	t_tuple v;
	v.x = x;
	v.y = y;
	v.z = z;
	v.w = 0;
	return (v);
}

double dot_product(t_tuple i, t_tuple j)
{
	return (i.x * j.x + i.y * j.y + i.z * j.z + i.w * j.w);
}

t_tuple	posit(t_ray ray, double t)
{
	t_tuple p;

	p = add_tuple(ray.origin, multi(ray.direction, t));
	return (p);
}

t_tuple place_normal(t_object o, t_tuple v)
{
	t_tuple		obj_pt;
	t_tuple		obj_norm;
	t_tuple		world_normal;
	t_matrix	m1;
	t_matrix	m2;

	if (o.id == 2)
		world_normal.w = 0;
	w1 = inverse(o.transform);
	obj_point = matrix_x_vextor(m1, v);
	obj_norm = normal_placement(o, obj_pt);
	m2 = transpose(m1);
	world_normal = matrix_x_vextor(m2, obj_norm);
	world_normal.w = 0;
	free_matrix(&m1);
	free_matrix(&m2);
	return (quake_normalize(world_normal));
}
