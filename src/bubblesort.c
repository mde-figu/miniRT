/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubblesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 21:40:23 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/06 21:48:34 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

static t_list	*swap(t_list *ptr1, t_list *ptr2)
{
	t_list	*tmp;

	tmp = ptr2->next;
	ptr2->next = ptr1;
	ptr1->next = tmp;
	return (ptr2);
}

void	bubblesort(t_list **xs)
{
	t_list		**tmp;
	t_list		*p1;
	t_list		*p2;
	t_iter		p;

	init_iter(&p, *xs);
	while (**p.i < p.n)
	{
		p.j = -1;
		tmp = xs;
		p.swapped = 0;
		while (++p.j < p.n - 1)
		{
			p1 = *tmp;
			p2 = (*tmp)->next;
			if (p1->content.t > p2->content.t)
			{
				*tmp = swap(p1, p2);
				p.swapped = 1;
			}
			tmp = &(*tmp)->next;
		}
		if (p.swapped == 0)
			break ;
	}
}
