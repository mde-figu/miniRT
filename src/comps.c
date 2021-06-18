/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:16:49 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/18 02:16:52 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

t_comps	pre_comp(t_intersect i, t_ray r)
{
	t_comps	cp;

	cp.t = i.t;
	cp.object = i.object;
	cp.point = posit(r, cp.t);
	cp.eyev = scale_tuple(r.direction, -1);
	if (ft_memcmp("triangle", i.object.type, 9) != 0)
		cp.normalv = place_normal(cp.object, cp.point);
	else
		cp.normalv = i.object.normal;
	cp.over_point = add_tuple(cp.point, scale_tuple(cp.normalv, 0.01));
	if (dot_product(cp.normalv, cp.eyev) < 0)
	{
		cp.inside = true;
		cp.normalv = scale_tuple(cp.normalv, -1);
	}
	else
		cp.inside = false;
	return (cp);
}
