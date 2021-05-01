/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 20:14:56 by mde-figu          #+#    #+#             */
/*   Updated: 2021/04/30 23:18:24 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parameters.h"

static void	sign_check(char *c, int *neg, int *i, const char *nptr)
{
	if (*c == '-')
	{
		(*i)++;
		*neg = 1;
		*c = *(nptr + *i);
	}
}

static void decimal_check(char *c, t_respar *p, int *i)
{
	if (*c != '.')
	{
		p->val = (p->val * 10) + (c - '0');
		if (p->flag == 1)
			--(*j);
	}
}
static int	iterator(char *c, t_respar *p, int *i, const char *nptr)
{
	int i;

	i = 0;
	while (*c != '\0')
	{
		decimal_check(*c, p, &i):
		if (*c == '.')
		{
			if (p->flag == 1)
				return (0);
			p->flag = 1;
		}
		++(*i);
		*c = *(nptr + *i);
	}
	p->val = p->val * ft_pow(10, i);
	return (1);
}
float		a_to_f(const char *nptr)
{
	int		 i;
	t_respar p;
	int		neg;
	char	c;

	i = 0;
	p.flag = 0;
	p.val = 0;
	neg = 0;
	c = *(nptr + i);
	sign_check(&c, &neg, &i, nptr);
	if (aux2(&c, &p, &i, nptr) == 0)
		return (0);
	if (neg)
		p.val = p.val * -1;
	return ((float)p.val);
}