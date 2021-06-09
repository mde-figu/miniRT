/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_cy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 19:51:41 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/08 00:58:03 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

static	t_matrix	posit_cy(char *position, char *diameter)
{
	t_matrix	a;
	t_matrix	d;
	t_matrix	c;
	char		**temp;
	t_tuple		p;

	temp = ft_split(position, ',');
	p.x = atof(temp[0]);
	p.y = atof(temp[1]);
	p.z = atof(temp[2]);
	a = translation(p.x, p.y, p.z);
	d = scaling(atof(diameter) / 2, 1, atof(diameter) / 2);
	c = matrix_multi(a, d);
	free_entry(&temp);
	free_matrix(&a);
	free_matrix(&d);
	return (c);
}

static	t_matrix	color_normal(t_object *o, char *cor, char *normal)
{
	char		**temp;
	t_color		cc;
	t_tuple		p;
	t_matrix	a;

	temp = ft_split(cor, ',');
	cc.red = (double)ft_atoi(temp[0]);
	cc.green = (double)ft_atoi(temp[1]);
	cc.blue = (double)ft_atoi(temp[2]);
	o->material = mat_par();
	o->material.color = scalar_color(cc, 0.003921569);
	o->material.specular = 0;
	free_entry(&temp);
	temp = ft_split(normal, ',');
	p.x = atof(temp[0]);
	p.y = atof(temp[1]);
	p.z = atof(temp[2]);
	o->normal = create_tuple(p.x, p.y, p.z, 1);
	o->minimum = 0;
	free_entry(&temp);
	a = rotate(create_tuple(p.x, p.y, p.z, 0));
	return (a);
}

void	config_cy(t_initpara *initpara, t_obj_par p, char **entry_t)
{
		t_object	o;
		t_matrix	a;
		t_matrix	d;
		t_matrix	c;
		float		s;

		p.position = entry_t[1];
		p.normal = entry_t[2];
		p.diameter = entry_t[3];
		p.height = entry_t[4];
		p.color = entry_t[5];
		o = cylinder();
		c = posit_cy(p.position, p.diameter);
		a = color_normal(&o, p.color, p.normal);
		d = matrix_multi(a, c);
		copy_matrix(&o.transform, d);
		free_matrix(&a);
		free_matrix(&c);
		free_matrix(&d);
		s = atof(p.height);
		o.maximum = s;
		o.closed = true;
		list_obj(&initpara->objects, o);
}
