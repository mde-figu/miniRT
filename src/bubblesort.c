/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubblesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 21:40:23 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/09 20:39:04 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

void	init_iter(t_iter *p, t_interl *xs)
{
	p->i = 0;
	p->j = -1;
	p->swapped = 0;
	p->n = list_size_inter(xs);
}

static t_interl	*swap(t_interl *ptr1, t_interl *ptr2)
{
	t_interl	*tmp;

	tmp = ptr2->next;
	ptr2->next = ptr1;
	ptr1->next = tmp;
	return (ptr2);
}

void	bubblesort(t_interl **xs)
{
	t_interl		**tmp;
	t_interl		*p1;
	t_interl		*p2;
	t_iter			p;

	init_iter(&p, *xs);
	while (++p.i < p.n)
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
