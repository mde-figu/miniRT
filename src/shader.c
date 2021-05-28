/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:29:06 by mde-figu          #+#    #+#             */
/*   Updated: 2021/05/28 14:09:15 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/components.h"
#include "../include/parameters.h"
#include "../include/canvas.h"
#include "../include/entries.h"

bool		the_shadow_knows (t_light light, t_initpara w, t_tuple point)
{
	t_tuple			v;
	t_raypara		p;
	t_ray			r;
	t_list			*intersections;
	t_intersect		h;

	v = subtract_tuple(light.position, point);
	p.distance = tuple_mag(v);
	p.direction = quake_normalize(v);
	r = ray(point, p.direction);
	intersections = intersect_world(w, r);
	h = hit(intersections);
	if (intersections != NULL)
		ft_lstclear(&intersections)
	if (h.valid == true && h.t < p.distance)
		return (true);
	else
		return (false);
}

static void	ft_init(t_colcomp *i, t_initpara w, t_comps, t_light c)
{
	i->a = world.ambient;
	i->material = comps.object.material;
	i->light = c;
	i->position = comps.over_point;
	i->eyev = comps.eyev;
	i->normalv = comps.normalv;
}

static t_color	color_mix(t_light l, t_colcomp *i, t_color c2, t_shadepar p)
{
	t_color		c1;

	p.shadowed = the_shadow_knows(l, p.world, p.comps.over_point);
	ft_init(i, p.world, p.comps, l);
	i.in_shadow = p.shadowed;
	c1 = lighting(*i);
	c2 = add_color(c1, c2);
	return (c2);
}

t_color		shadding(t_initpara w, t_comps comp)
{
	t_lights	tmp;
	t_shadepar	p;
	t_colcomp	i;
	t_colmix	c;

	c.c1 = create_color(0, 0, 0);
	c.c2 = create_color(0, 0, 0);
	tmp = w.lights;
	if (w.has_light)
	{
		while (tmp->next)
		{
			p.shadowed = the_shadow_knows(tmp->content, world, comp.over_point);
			ft_init(&i, world, comps, tmp->content);
			i.in_shadow = p.shadowed;
			c.c1 = lighting(i);
			c.c2 = add_color(c.c1, c.c2);
			tmp = tmp->next;
		}
		p.world =  w;
		p.comps = comp;
		c.c2 = color_mix(tmp->content, &i, c.c2, p);
		return (c.c2);
	}
	else
		return (w.ambient);
}
