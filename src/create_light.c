/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 23:56:35 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/25 20:37:25 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

void	create_light(t_initpara *initpara, t_light light)
{
	t_lights	*tmp;

	initpara->lightonoff = true;
	if (list_size_lig(initpara->world_lights) == 0)
	{
		initpara->world_lights = list_new_lig(light);
	}
	else
	{
		tmp = initpara->world_lights;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = list_new_lig(light);
	}
}
