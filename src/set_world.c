/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_world.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 13:41:29 by mirkios           #+#    #+#             */
/*   Updated: 2021/06/17 19:08:19 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

void	ini_world(t_initpara *initpara, t_object content)
{
	t_objects	*tmp;

	initpara->lightonoff = 0;
	initpara->world_lights = NULL;
	if (list_size_world(initpara->world_objects) == 0)
		initpara->world_objects = list_new_world(content);
	else
	{
		tmp = initpara->world_objects;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = list_new_world(content);
	}
	initpara->num_objects = list_size_world(initpara->world_objects);
}

void	set_world(t_initpara *initpara)
{
	t_objects	*tmp;
	t_lights	*tmp_l;

	initpara->world_objects = NULL;
	initpara->world_lights = NULL;
	tmp = initpara->objects;
	while (tmp->next)
	{
		ini_world(initpara, tmp->content);
		tmp = tmp->next;
	}
	ini_world(initpara, tmp->content);
	tmp_l = initpara->lighting;
	if (tmp_l != NULL)
	{
		while (tmp_l->next)
		{
			create_light(initpara, tmp_l->content);
			tmp_l = tmp_l->next;
		}
		create_light(initpara, tmp_l->content);
	}
	initpara->ambient = initpara->init_color;
}
