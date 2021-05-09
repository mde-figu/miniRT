/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_world.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 13:41:29 by mirkios           #+#    #+#             */
/*   Updated: 2021/05/08 21:52:03 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"
#include "../include/components.h"

void	world(t_world *world, t_object content)
{
	t_object	*tmp;
	world->has_light = 0;
	world->lights = NULL;
	if (list_size_world(world->objects) == 0)
		world->objects = list_size_world(content);
	else
	{
		tmp = world->objects;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = list_size_world(content);
	}
	world->num_objects = list_size_world(world->objects);
}

void	set_world(t_world *world, t_initpara initpara)
{
	t_initpara	*tmp;
	t_lights	*tmp_l;

	world->objects = NULL;
	world->lights = NULL;
	tmp = initpara.objects;
	while (tmp->next)
	{
		world(world, tmp->content);
		tmp = tmp->next;
	}
}