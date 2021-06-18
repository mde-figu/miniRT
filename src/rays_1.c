/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 21:58:39 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/18 02:01:14 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

t_ray	ray(t_tuple origin, t_tuple direction)
{
	t_ray	r;

	r.origin = origin;
	r.direction = direction;
	return (r);
}

t_tuple	posit(t_ray ray, double t)
{
	t_tuple	p;

	p = add_tuple(ray.origin, scale_tuple(ray.direction, t));
	return (p);
}

t_intersect	ray_hit(t_interl *xs)
{
	t_intersect	it;
	int			i;
	int			lenght;
	t_interl	*tmp;

	i = 0;
	tmp = xs;
	lenght = list_size_inter(xs);
	it.valid = false;
	bubblesort(&xs);
	while (i < lenght)
	{
		if (tmp->content.t > 0)
		{
			it.t = tmp->content.t;
			it.object = tmp->content.object;
			it.valid = true;
			break ;
		}
		tmp = tmp->next;
		i++;
	}
	return (it);
}
