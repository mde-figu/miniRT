/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_sq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:34:26 by mde-figu          #+#    #+#             */
/*   Updated: 2021/05/19 18:52:18 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/components.h"
#include "../include/parameters.h"

static t_matrix posit(t_object *o, char *pos, char *col, char *size)
{
	char		**tmp;
	t_tuple		p;
	t_color		c;
	t_matrix	d;

	tmp = ft_split(pos, ',');
	p.x = atof(tmp[0]);
	p.y = atof(tmp[1]);
	p.z = atof(tmp[2]);
	o->center = create_point(p.x, p.y, p.z);
	o->side = atof(size);
	free_entry(&tmp);
	tmp = ft_split(col, ',');
	c.red = (double)ft_atoi(tmp[0]);
	c.green = (double)ft_atoi(tmp[1]);
	c.blue = (double)ft_atoi(tmp[2]);
	free_entry(&tmp);
	o->material = material();
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
	p.x = atof(tmp[0]);
	p.y = atof(tmp[1]);
	p.z = atof(tmp[2]);
	o->normal = create_vector(p.x, p.y, p.z);
	free_entry(&tmp);
	return (p);
}

void	config_sq(t_initpara *initpara, char *pos, char *n, t_obj2_par p)
{
	t_object	o;
	t_matrix	c;
	t_matrix	a;
	t_matrix	d;
	t_tuple		po;

	o = square();
	c = posit(&o, pos, p.cor, p.size);
	po = normal(&o, n);
	a = rotation(create_vector(po.x, po.y, po.z));
	d = matrix_multi(a, c);
	copy_matrix(&o.transform, d);
	free_matrix(&a);
	free_matrix(&c);
	free_matrix(&d);
	objects(&initpara->objects, o);
}
