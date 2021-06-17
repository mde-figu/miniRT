/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 20:14:56 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/16 18:22:24 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

static void	ft_aux(char c, t_respar1 *p, int *j)
{
	if (c != '.')
	{
		p->val = (p->val * 10) + (c - '0');
		if (p->flag == 1)
			--(*j);
	}
}

static void	ft_aux2(char *c, const char *nptr, bool *neg, int *i)
{
	if (*c == '-')
	{
		(*i)++;
		*neg = true;
		*c = *(nptr + *i);
	}
}

static void	ft_init(int *i, t_respar1 *p, bool *neg)
{
	*i = 0;
	p->flag = 0;
	p->val = 0;
	*neg = False;
}

static int	ft_aux3(char *c, const char *nptr, t_respar1 *p, int *i)
{
	int	j;

	j = 0;
	while (*c != '\0')
	{
		ft_aux(*c, p, &j);
		if (*c == '.')
		{
			if (p->flag == 1)
				return (0);
			p->flag = 1;
		}
		++(*i);
		*c = *(nptr + *i);
	}
	p->val = p->val * ft_pow(10, j);
	return (1);
}

double	atof(const char *nptr)
{
	int		i;
	t_respar1	p;
	bool	neg;
	char	c;

	ft_init(&i, &p, &neg);
	c = *(nptr + i);
	ft_aux2(&c, nptr, &neg, &i);
	if (ft_aux3(&c, nptr, &p, &i) == 0)
		return (0);
	if (neg)
		p.val = p.val * -1;
	return ((float)p.val);
}
