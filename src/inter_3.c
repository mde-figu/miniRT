/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 21:04:13 by mde-figu          #+#    #+#             */
/*   Updated: 2021/05/24 21:45:30 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/components.h"
#include "../include/canvas.h"

static t_list	cap_inter(t_cyinter p; t_capinter *c, t_object cyl, t_ray ray)
{
	t_list	*ret;

	ret = NULL;
	if (fabs(p.a) < EPSILON)
	{
		p.cc = 1;
		c->xs_cap = intersect_caps(cyl, ray);
	}
	if (p.cc == 0)
	{
		if (cyl_inter_aux(p, ray, c, cyl) != NULL)
			return (c->xs);
	}
	return (ret);
}

static t_list	*cyl_list(t_capinter *c)
{
	if (c->xs != NULL)
	{
		ft_lstclear(&c->xs);
		c->xs = NULL;
	}
	return (c->xs_cap);
}

t_list	*intersect_cylinder(t_object cyl, t_ray ray)
{
	t_cyinter	p;
	t_capinter	c;

	c.xs = NULL;
	c.xs_cap = NULL;
	p.cc = 0;
	p.a = ray.direction.x * ray.direction.x + ray.direction.z * ray.direction.z;
	if (cap_inter(p, &c, cyl, ray) != NULL)
		return (c.xs);
	if (p.cc == 1)
		cyl_list(&c);
	else if (ft_lstsize(c.xs_cap) == 0)
	{
		if (c.xs_cap != NULL)
		{
			ft_lstclear(&c.xs_cap)
			c.xs_cap = NULL;
		}
		return (c.xs);
	}
	else
		ft_lstadd_back(&c.xs, c.xs_cap);
	return (c.xs);
}
