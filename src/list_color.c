/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:53:58 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/21 11:54:14 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

static void	check_xs(t_interl **xs, t_interl *init)
{
	if (init != NULL)
	{
		if (*xs == NULL)
			*xs = init;
		else
			list_addback_inter(&*xs, init);
	}
}

t_interl	*world_intersect(t_initpara w, t_ray r)
{
	t_interl	*xs;
	t_interl	*init;
	t_objects	*tmp;

	xs = NULL;
	init = NULL;
	tmp = w.objects;
	while (tmp->next)
	{
		init = intersect(tmp->content, r);
		if (init != NULL)
		{
			if (xs == NULL)
				xs = init;
			else
				list_addback_inter(&xs, init);
		}
		tmp = tmp->next;
	}
	init = intersect(tmp->content, r);
	check_xs(&xs, init);
	return (xs);
}

t_color	list_color(t_initpara initpara, t_ray ray)
{
	t_interl	*wwl;
	t_color		c;
	t_intersect	in;
	t_comps		comps;

	wwl = world_intersect(initpara, ray);
	in = ray_hit(wwl);
	if (wwl != NULL)
		list_clear_inter(&wwl);
	if (in.valid == false)
	{
		c = create_color(0, 0, 0);
		return (c);
	}
	else
	{
		comps = pre_comp(in, ray);
		c = shadding(initpara, comps);
		return (c);
	}
}
