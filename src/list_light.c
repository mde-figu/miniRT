/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:18:39 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/09 20:39:52 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

t_lights	*list_new_lig(t_light content)
{
	t_lights	*new;

	new = (t_lights *)malloc(sizeof(t_lights));
	if (!new)
		return (NULL);
	if (new)
		new->content = content;
	new->next = NULL;
	return (new);
}

int	list_size_lig(t_lights *lst)
{
	int			i;
	t_lights	*tmp;

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
