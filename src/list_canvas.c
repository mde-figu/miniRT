/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_canvas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:55:45 by mde-figu          #+#    #+#             */
/*   Updated: 2021/05/19 20:16:03 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/components.h"
#include "../include/entries.h"

t_canvasl	*list_new_canvas(t_canvas cv)
{
	t_canvasl	*new;

	new = (t_canvasl *)malloc(sizeof(t_canvasl));
	if (!new)
		return (NULL);
	if (new)
		new->content = cv;
	new->next = NULL;
	return (new);
}

int		list_size_canvas(t_canvasl *cv)
{
	int			i;
	t_canvasl	tmp;

	if (cv)
	{
		i = 1;
		tmp = cv;
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

void	list_canvas(t_canvasl **l, t_canvas canvas)
{
	t_canvasl	*tmp;

	if (list_size_canvas(*l) == 0)
		*l = list_new_canvas(canvas);
	else
	{
		tmp = *l;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = list_new_canvas(canvas);
	}
}
