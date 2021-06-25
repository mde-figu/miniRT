/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 20:14:56 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/25 18:47:37 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

static void	atofinit(t_atofpar *atofpar)
{
	atofpar->i = 0;
	atofpar->j = 0;
	atofpar->val = 0;
	atofpar->flag = 0;
	atofpar->minus = 1;
}

double	ft_atof(char *str)
{
	t_atofpar	atofpar;

	atofinit(&atofpar);
	atofpar.c = *(str + atofpar.i);
	while (atofpar.c != '\0')
	{
		if (atofpar.c == '-')
			atofpar.minus = -1;
		if (atofpar.c != '.' && atofpar.c != '-')
		{
			atofpar.val = (atofpar.val * 10) + (atofpar.c - '0');
			if (atofpar.flag == 1)
				--atofpar.j;
		}
		if (atofpar.c == '.')
		{
			if (atofpar.flag == 1)
				return (0);
			atofpar.flag = 1;
		}
		++atofpar.i;
		atofpar.c = *(str + atofpar.i);
	}
	atofpar.val = atofpar.val * ft_pow(10, atofpar.j);
	return (atofpar.val * atofpar.minus);
}
