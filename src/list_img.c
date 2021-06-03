/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 20:30:41 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/01 20:34:38 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/canvas.h"

int	lst_size_img(t_imgg *img)
{
	int		i;
	t_imgg	*tmp;

	if (img)
	{
		i = 1;
		tmp = img;
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

t_imgg	*ft_lstnew_img(t_data img)
{
	t_imgg	*new;

	new = (t_imgg *)malloc(sizeof(t_imgg));
	if (!new)
		return (NULL);
	if (new)
		new->content = img;
	new->next = NULL;
	return (new);
}

void	ft_lstclear_img(t_imgg **img)
{
	t_imgg	*current;
	t_imgg	*next;

	current = *img;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*img = NULL;
}
