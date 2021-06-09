/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 22:15:33 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/06 21:39:55 by mde-figu         ###   ########.fr       */
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
	if (x * x + z * z -1 <= EPSILON)
		r = true;
	return (r);
}

t_list *intersect_caps(t_object cyl, t_ray ray)
{
	t_intersect i1;
	t_list		*xs;
	t_list		*ii;
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
		if (ft_lstsize(xs) == 1)
			ft_lstadd_back(&xs, ii);
		else
			xs = list_new_inter(i1);
	}
	return (xs);
}

static void	aux(t_list **xs, t_list *init)
{
	if (init != NULL)
	{
		if (*xs == NULL)
			*xs = init;
		else
			ft_lstadd_back(&*xs, init);
	}
}

t_list		*intersect_world(t_initpara w, t_ray r)
{
	t_list		*xs;
	t_list		*ini;
	t_objects	*tmp;

	xs = NULL;
	ini = NULL;
	tmp = w.objects;
	while (tmp->next)
	{
		ini = intersect(tmp->content, r);
		if (ini != NULL)
		{
			if (xs == NULL)
				xs = ini;
			else
				ft_lstadd_back(&xs, ini);
		}
		tmp = tmp->next;
	}
	ini = intersect(tmp->content, r);
	aux(&xs, ini);
	bubblesort(&xs);
	return (xs);
}
