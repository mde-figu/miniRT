/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 22:15:33 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/24 19:51:13 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

static bool	check_cap(t_ray ray, double t)
{
	bool	r;
	double	x;
	double	z;

	r = false;
	x = ray.origin.x + t * ray.direction.x;
	z = ray.origin.z + t * ray.direction.z;
	if (x * x + z * z - 1 <= EPSILON)
		r = true;
	return (r);
}

t_interl	*intersect_caps(t_object cyl, t_ray ray)
{
	t_intersect	i1;
	t_interl	*xs;
	t_interl	*ii;
	double		t;

	xs = NULL;
	i1.valid = false;
	if (cyl.closed == false || fabs(ray.direction.y) < EPSILON)
		return (xs);
	t = (cyl.minimum - ray.origin.y) / ray.direction.y;
	i1 = intersection(t, cyl);
	if (check_cap(ray, t))
		xs = list_new_inter(i1);
	t = (cyl.maximum - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, t))
	{
		i1 = intersection(t, cyl);
		ii = list_new_inter(i1);
		if (list_size_inter(xs) == 1)
			list_addback_inter(&xs, ii);
		else
			xs = list_new_inter(i1);
	}
	return (xs);
}
