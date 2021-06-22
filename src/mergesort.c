/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:03:43 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/21 20:10:03 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

static t_interl	*sortedmerge(t_interl *a, t_interl *b)
{
	t_interl	*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (a->content.t <= b->content.t)
	{
		result = a;
		result->next = sortedmerge(a -> next, b);
	}
	else
	{
		result = b;
		result->next = sortedmerge(a, b -> next);
	}
	return (result);
}

static void	frontbacksplit(t_interl *source, t_interl **front, t_interl **back)
{
	t_interl	*fast;
	t_interl	*slow;

	if (source == NULL || source->next == NULL)
	{
		*front = source;
		*back = NULL;
	}
	else
	{
		slow = source;
		fast = source -> next;
		while (fast != NULL)
		{
			fast = fast -> next;
			if (fast != NULL)
			{
				slow = slow -> next;
				fast = fast -> next;
			}
		}
		*front = source;
		*back = slow -> next;
		slow -> next = NULL;
	}
}

void	mergesort(t_interl	**headref)
{
	t_interl	*head;
	t_interl	*a;
	t_interl	*b;

	head = *headref;
	if ((head == NULL) || (head -> next == NULL))
		return ;
	frontbacksplit(head, &a, &b);
	mergesort(&a);
	mergesort(&b);
	*headref = sortedmerge(a, b);
}
