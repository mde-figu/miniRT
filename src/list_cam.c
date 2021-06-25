/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 20:04:29 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/25 17:03:23 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

t_cameras	*list_new_cam(t_camera content)
{
	t_cameras	*new;

	new = (t_cameras *)malloc(sizeof(t_cameras));
	if (!new)
		return (NULL);
	if (new)
		new->content = content;
	new->next = NULL;
	return (new);
}

int	list_size_cam(t_cameras *lst)
{
	int			i;
	t_cameras	*temp;

	if (lst)
	{
		i = 1;
		temp = lst;
		while (temp->next)
		{
			temp = temp->next;
			i++;
		}
		return (i);
	}
	else
		return (0);
}
