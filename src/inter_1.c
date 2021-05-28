/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 12:55:33 by mde-figu          #+#    #+#             */
/*   Updated: 2021/05/21 19:04:23 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/components.h"
#include "../include/canvas.h"

t_intersect	intersection(double t, t_object o)
{
	t_intersect i;

	i.t = t;
	i.object = o;
	i.valid = true;
	return (i);
}

t_list	*intersect_plan(t_object p, t_ray ray)
{
	t_list			*xs;
	t_intersect		i;
	double			t;

	xs = NULL;
	if (fabs(ray.direction.y) < EPSILON)
		return (xs);
	t = ray.originy / ray.direction.y;
	i = intersection(t, p);
	xs = ft_lstnew(i);
	return (xs);
}

t_list	*intersect_square(t_object p, t_ray ray)
{
	t_list			*xs;
	t_intersect		i;
	double			t;
	t_tuple			point;
	double			border;

	xs = NULL;
	if (fabs(ray.direction.y) < EPSILON)
		return (xs);
	t = -ray.origin.y / ray .direction.y;
	if (t > 0)
	{
		point = subtract_tuple(add_tuple(ray.origin, scale_tuple(ray.direction, t)), p.center);
		border = p.side * 0.5;
		if ((fabs(point.x) <= border) && (fabs(point.y)
				<= border) && (fabs(point.z) <= border))
		{
			i = intersection(t, p);
			xs = ft_lstnew(i);
		}
	}
	return (xs);
}

t_list	*intersect_triangle(t_object triangle, t_ray ray)
{
	t_tuple		dir_cross_e2;
	t_tuple		p1_to_origin;
	t_tuple		origin_cross_e1;
	t_list		*xs;
	t_trinter	p;

	xs = NULL;
	dir_cross_e2 = cross_product(ray.direction, triangle.e2);
	p.det = dot_product(triangle.e1, dir_cross_e2);
	if (fabs(p.det) < EPSILON)
		return (xs);
	p.f = 1.0 / p.det;
	p1_to_origin = subtract_tuple(ray.origin, triangle.p1);
	p.u = p.f * dot_product(p1_to_origin, dir_cross_e2);
	if (p.u < 0 || p.u > 1)
		return (xs);
	origin_cross_e1 = cross_product(p1_to_origin, triangle.e1);
	p.v = p.f * dot_product(ray.direction, origin_cross_e1);
	if (p.v < 0 || (p.u + p.v) > 1)
		return (xs);
	p.t = p.f * dot_product(triangle.e2, origin_cross_e1);
	p.i1 = intersection(p.t, triangle);
	xs = ft_lstnew(p.i1);
	return (xs);
}
