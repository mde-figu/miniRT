/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_cy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 19:51:41 by mde-figu          #+#    #+#             */
/*   Updated: 2021/05/12 12:11:19 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parameters.h"
#include "../include/entries.h"
#include "../include/entries.h"

void	config_cy(t_initpara initpara, t_obj_par p, char **entry_t) // paco diz, entry_t precisa de duas *
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
		c = posit(p.position, p.diameter);
		a = color_normal(&o, p.color, p.normal);  // AQUI
		d = matrix multiplier(a, c); //AQUI
		copy_matrix(&o.transform, d);
		free_matrix(&a);
		free_matrix(&c);
		free_matrix(&d);
		s = atof(p.height);
		o.maximum = s;
		o.closed = true;
		objects(&initpara->objects, o);
}
