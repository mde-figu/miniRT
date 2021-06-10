/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_world.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 13:41:29 by mirkios           #+#    #+#             */
/*   Updated: 2021/06/10 14:34:26 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

void	iworld(t_world *world, t_object content)
{
	t_objects	*tmp;
	world->has_light = 0;
	world->lights = NULL;
	if (list_size_world(world->objects) == 0)
		world->objects = list_new_world(content);
	else
	{
		tmp = world->objects;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = list_new_world(content);
	}
	world->num_objects = list_size_world(world->objects);
}

void	set_world(t_world *world, t_initpara initpara)
{
	t_objects	*tmp;
	t_lights	*tmp_l;

	world->objects = NULL;
	world->lights = NULL;
	tmp = initpara.objects;
	while (tmp->next)
	{
		iworld(world, tmp->content);
		tmp = tmp->next;
	}
	iworld(world, tmp->content);
	tmp_l = initpara.lighting;
	if (tmp_l != NULL)
	{
		while (tmp_l->next)
		{
			create_light(world, tmp_l->content);
			tmp_l = tmp_l->next;
		}
		create_light(world, tmp_l->content);
	}
	world->ambient = initpara.init_color;
}
