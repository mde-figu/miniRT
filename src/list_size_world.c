/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_size_world.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 21:39:24 by mde-figu          #+#    #+#             */
/*   Updated: 2021/05/08 21:45:58 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/components.h"

int	list_size_world(t_objects *lst)
{
	int			i;
	t_objects	*tmp;

	if (lst)
	{
		i = 1;
		tmp = lst;
		while (tmp->next)
		{
			tmp = tmp->next;
			i++;
		}
		return (i);
	}
	return (0);
}
