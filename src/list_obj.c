/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:39:00 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/09 19:30:13 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

t_objects	*list_new_obj(t_object content)
{
	t_objects	*nouveau;

	nouveau = (t_objects *)malloc(sizeof(t_objects));
	if (!nouveau)
		return (NULL);
	if (nouveau)
		nouveau->content = content;
	nouveau->next = NULL;
	return (nouveau);
}

int	list_size_obj(t_objects *lst)
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

void	list_obj(t_objects **l, t_object o)
{
	t_objects	*tmp;

	if (list_size_obj(*l) == 0)
		*l = list_new_obj(o);
	else
	{
		tmp = *l;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = list_new_obj(o);
	}
}
