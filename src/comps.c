/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:16:49 by mde-figu          #+#    #+#             */
/*   Updated: 2021/05/31 16:34:31 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parameters.h"

t_comps	pre_comp(t_intersection i, t_ray r)
{
	t_comps	cp;

	cp.t = i.t;
	cp.object = i.object;
	cp.point = posit(r, cp.t);
	compseyey = scalar_tuple(r.direction, -1);
	if (ft_memcmp("triangle", i.object.type, 9) != 0)
		cp.normalv = place_normal(cp.object, cp.point);
	else
		cp.normalv = i.object.normal;
	cp.over_point = add_tuple(cp.point, scalar_tuple(cp.normalv, 0.01));
	if (dot_product(comps.normalv, comps.eyev) < 0)
	{
		comps.inside = true;
		comps.normalv = negate_tuple(comps.normalv);
	}
	else
		comps.inside = false;
}
