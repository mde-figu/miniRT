/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_sp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:57:03 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/25 14:01:21 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

static void	color(t_object *o, char *col)
{
	char	**tmp;
	t_color	c;

	tmp = ft_split(col, ',');
	c.red = (double)ft_atoi(tmp[0]);
	c.green = (double)ft_atoi(tmp[1]);
	c.blue = (double)ft_atoi(tmp[2]);
	o->material = mat_par();
	o->material.color = scalar_color(c, 0.003921569);
	free_entry(&tmp);
}

static	t_matrix	position(char *pos, double r)
{
	t_matrix	a;
	t_matrix	b;
	t_matrix	c;
	char		**tmp;
	t_tuple		p;

	tmp = ft_split(pos, ',');
	p.x = round(ft_atof(tmp[0]));
	p.y = round(ft_atof(tmp[1]));
	p.z = round(ft_atof(tmp[2]));
	free_entry(&tmp);
	a = translation(p.x, p.y, p.z);
	b = scaling(r, r, r);
	c = matrix_multi(a, b);
	free_matrix(&a);
	free_matrix(&b);
	return (c);
}

void	config_sp(t_initpara *initpara, char *pos, char *dia, char *col)
{
	t_object	o;
	t_matrix	c;
	double		r;

	o = sphere();
	r = ft_atof(dia) / 2;
	c = position(pos, r);
	copy_matrix(&o.transform, c);
	free_matrix(&c);
	color(&o, col);
	list_obj(&initpara->objects, o);
}
