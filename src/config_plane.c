/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:44:36 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/09 17:03:59 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

static t_matrix plane_posit(t_object *o, char *pos, char *col)
{
	char		**tmp;
	t_tuple		p;
	t_matrix	m;
	t_color		c;

	tmp = ft_split(pos, ',');
	p.x = atof(tmp[0]);
	p.y = atof(tmp[1]);
	p.z = atof(tmp[2]);
	free_entry(&tmp);
	tmp = ft_split(col, ',');
	c.red = (double)ft_atoi(tmp[0]);
	c.green = (double)ft_atoi(tmp[1]);
	c.blue = (double)ft_atoi(tmp[2]);
	m = translation(p.x, p.y, p.z);
	o->material = mat_par();
	o->material.color = scalar_color(c, 0.003921569);
	o->material.specular = 0;
	return (m);
}

static t_matrix	normal(char *normal)
{
	char		**tmp;
	t_tuple		p;
	t_matrix	a;

	tmp = ft_split(normal, ',');
	p.x = atof(tmp[0]);
	p.y = atof(tmp[1]);
	p.z = atof(tmp[2]);
	free_entry(&tmp);
	a = rotate(create_tuple(p.x, p.y, p.z, 0));
	return (a);
}

void	config_pl(t_initpara *initpara, char *pos, char *n, char *col)
{
	t_object	o;
	t_matrix	a;
	t_matrix	c;
	t_matrix	d;

	o = plane();
	c = plane_posit(&o, pos, col);
	a = normal(n);
	d = matrix_multi(a, c);
	copy_matrix(&o.transform, d);
	free_matrix(&a);
	free_matrix(&c);
	free_matrix(&d);
	list_obj(&initpara->objects, o);
}
