/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 23:56:35 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/09 20:29:39 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

void	create_light(t_world *world, t_light light)
{
	t_lights	*tmp;

	world->has_light = 1;
	if (list_size_lig(world->lights) == 0)
	{
		world->lights = list_new_lig(light);
	}
	else
	{
		tmp = world->lights;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = list_new_lig(light);
	}
}