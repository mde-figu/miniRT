/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_tr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 18:37:45 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/15 19:51:57 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

static t_object	assign_vertex(char *v1, char *v2, char *v3)
{
	char		**tmp;
	t_tuple		p1;
	t_tuple		p2;
	t_tuple		p3;

	tmp = ft_split(v1, ',');
	p1.x = atof(tmp[0]);
	p1.y = atof(tmp[1]);
	p1.z = atof(tmp[2]);
	free_entry(&tmp);
	tmp = ft_split(v2, ',');
	p2.x = atof(tmp[0]);
	p2.y = atof(tmp[1]);
	p2.z = atof(tmp[2]);
	free_entry(&tmp);
	tmp = ft_split(v3, ',');
	p3.x = atof(tmp[0]);
	p3.y = atof(tmp[1]);
	p3.z = atof(tmp[2]);
	free_entry(&tmp);
	return (triangle(5, create_tuple(p1.x, p1.y, p1.z, 1),
			create_tuple(p2.x, p2.y, p2.z, 1),
			create_tuple(p3.x, p3.y, p3.z, 1)));
}

void	config_tr(t_initpara *initpara, char **entry_t)
{
		t_object	o;
		t_color		cc;
		t_vtx_par	vt;
		char		**tmp;

		vt.p1 = entry_t[1];
		vt.p2 = entry_t[2];
		vt.p3 = entry_t[3];
		o = assign_vertex(vt.p1, vt.p2, vt.p3);
		tmp = ft_split(entry_t[4], ',');
		cc.red = (double)atof(tmp[0]);
		cc.green = (double)atof(tmp[1]);
		cc.blue = (double)atof(tmp[2]);
		o.material = mat_par();
		o.material.color = scalar_color(cc, 0.003921569);
		o.material.specular = 0;
		list_obj(&initpara->objects, o);
		free_entry(&tmp);
}
