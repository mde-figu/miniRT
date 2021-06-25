/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_inter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 21:32:59 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/25 16:50:54 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

t_interl	*list_new_inter(t_intersect content)
{
	t_interl	*new;

	new = (t_interl *)malloc(sizeof(t_interl));
	if (!new)
		return (NULL);
	if (new)
		new->content = content;
	new->next = NULL;
	return (new);
}

void	list_clear_inter(t_interl **lst)
{
	t_interl	*current;
	t_interl	*next;

	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*lst = NULL;
}

int	list_size_inter(t_interl *lst)
{
	int			i;
	t_interl	*temp;

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

void	list_addback_inter(t_interl **lst, t_interl *new)
{
	t_interl	*aux;

	aux = (*lst);
	if (!new)
		return ;
	if (!*lst)
		(*lst) = new;
	else
	{
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}
}
