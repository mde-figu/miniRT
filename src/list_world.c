/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 21:39:24 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/07 00:39:27 by mde-figu         ###   ########.fr       */
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
	else
		return (0);
}

t_objects	*list_new_world(t_object content)
{
	t_objects	*new;

	new = (t_objects *)malloc(sizeof(t_objects));
	if (!new)
		return (NULL);
	if (new)
		new->content = content;
	new->next = NULL;
	return (new);
}
