/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_sq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:34:26 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/25 18:34:17 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

static t_matrix	posit_sq(t_object *o, char *pos, char *col, char *size)
{
	char		**tmp;
	t_tuple		p;
	t_color		c;
	t_matrix	d;

	tmp = ft_split(pos, ',');
	p.x = ft_atof(tmp[0]);
	p.y = ft_atof(tmp[1]);
	p.z = ft_atof(tmp[2]);
	o->center = create_tuple(p.x, p.y, p.z, 1);
	o->side = ft_atof(size);
	free_entry(&tmp);
	tmp = ft_split(col, ',');
	c.red = (double)ft_atoi(tmp[0]);
	c.green = (double)ft_atoi(tmp[1]);
	c.blue = (double)ft_atoi(tmp[2]);
	free_entry(&tmp);
	o->material = mat_par();
	o->material.color = scalar_color(c, 0.003921569);
	o->material.specular = 0;
	d = translation(p.x, p.y, p.z);
	return (d);
}

static	t_tuple	normal(t_object *o, char *normal)
{
	char	**tmp;
	t_tuple	p;

	tmp = ft_split(normal, ',');
	p.x = ft_atof(tmp[0]);
	p.y = ft_atof(tmp[1]);
	p.z = ft_atof(tmp[2]);
	o->normal = create_tuple(p.x, p.y, p.z, 0);
	free_entry(&tmp);
	return (p);
}

void	config_sq(t_initpara *initpara, char **entry)
{
	t_object	o;
	t_matrix	c;
	t_matrix	a;
	t_matrix	d;
	t_tuple		po;

	o = square();
	c = posit_sq(&o, entry[1], entry[4], entry[3]);
	po = normal(&o, entry[2]);
	a = rotate(create_tuple(po.x, po.y, po.z, 0));
	d = matrix_multi(a, c);
	copy_matrix(&o.transform, d);
	free_matrix(&a);
	free_matrix(&c);
	free_matrix(&d);
	list_obj(&initpara->objects, o);
}
