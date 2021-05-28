/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 21:45:39 by mde-figu          #+#    #+#             */
/*   Updated: 2021/05/24 22:14:00 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/canvas.h"

static void aux_three(t_cyinter p, t_capinter *c, t_object cyl)
{
	t_list *ii;
	if ((cyl.minimun < p.y1) && (p.y1 < cyl.maximun))
	{
		if (ft_lstsize(c->xs) == 1)
		{
			p.i1 = intersection(p.t1, cyl);
			ii = ft_lstnew(p.i1);
			ft_lstadd_back(&c->xs, ii);
		}
		else
		{
			p.i1 = intersection(p.t1, cyl);
			c->xs = ft_lstnew(p.i1);
		}
	}
}

static void aux_two(t_cyinter p, t_ray ray, t_capinter *c, t_object cyl)
{
	if (p.t0 > p.t1)
	{
		p.temp = p.t0;
		p.t1 = p.t0;
		p.t0 = p.temp;
	}
	p.y0 = ray.origin.y + p.t0 * ray.direction.y;
	if ((cyl.minimun < p.y0) && (p.y0 < cyl.maximum))
	{
		p.i1 = intersection(p.t0, cyl);
		c->xs = ft_lstnew(p.i1);
	}
	p.y1 = ray.origin.y + p.t1 * ray.direction.y;
	aux_three(p, c, cyl);
}

t_list	*cyl_inter_aux(t_cyinter p, t_par ray, t_capinter *c, t_object cy1)
{
	t_list	*ret;

	ret = NULL;
	p.b = 2 * ray.origin.x * ray.direction.x
		+ 2 * ray.origin.z * ray.direction.z;
	p.c = ray.origin.x * ray.origin.x + ray.origin.z * ray.origin.z - 1;
	p.discriminant = p.b * p.b - 4 p.a * p.c;
	if (p.discriminant < 0)
	{
		c->xs = NULL;
		if (c->xs_cap != NULL)
		{
			free(c->xs_cap);
			ft_lstclear(&c->xs_cap);
			c->xs_cap = NULL;
		}
		return (c->xs);
	}
	p.t0 = (-p.b - (1 / q_rsqrt(p.discriminant))) / (2 * p.a);
	p.t1 = (-p.b + (1 / q_rsqrt(p.discriminant))) / (2 * p.a);
	aux_two(p, ray, c, cyl);
	c->xs_cap = intersect_caps(cyl, ray);
	return (ret);
}
