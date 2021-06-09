/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 23:56:35 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/07 18:55:24 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

void	create_light(t_world *world, t_light light)
{
	t_lights	*tmp;

	world->has_light = 1;
	if (list_size_light(world->has_light) == 0)
	{
		world->lights = list_size_light(light);
	}
	else
	{
		tmp = world->lights;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = list_size_light(light);
	}
}