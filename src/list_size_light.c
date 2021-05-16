/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_size_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 00:01:50 by mde-figu          #+#    #+#             */
/*   Updated: 2021/05/11 00:08:19 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"
#include "../include/components.h"

int	list_size_light(t_lights *list)
{
	int			i;
	t_lights	*tmp;

	if (list)
	{
		i = 1;
		tmp = list;
		while (tmp->next)
		{
			tmp = tmp->next;
			i++;
		}
		return (i);
	}
	else
		return (0);
}
