/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:53:58 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/06 19:52:51 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

static void check_xs(t_list **xs, t_list *init)
{
	if (init != NULL)
	{
		if (*xs == NULL)
			*xs = init;
		else
			ft_lstadd_back(&xs, init);
	}
}

t_list	*world_intersect(t_initpara w, t_ray r)
{
	t_list		*xs;
	t_list		*init;
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
				ft_lstadd_back(&xs, init);
		}
		tmp = tmp->next;
	}
	init = intersect(tmp->content, r);
	check_xs(&xs, init);
	bubblesort(&xs);
	return (xs);
}

t_color	list_color(t_initpara initpara, t_ray ray)
{
	t_list		*wwl;
	t_color		c;
	t_intersect	in;
	t_comps		comps;

	wwl = world_intersect(initpara, ray);
	in = hit(wwl);
	if (wwl !== NULL)
		ft_lstclear(&wwl);
	if (in.valid == false)
	{
		c = create_color(0, 0, 0);
		return (c);
	}
	else
	{
		comps = pre_comp(in, ray);
		c = shadding(wordl, comps);
		return (c);
	}
}
