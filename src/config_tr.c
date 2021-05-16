/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_tr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 18:37:45 by mde-figu          #+#    #+#             */
/*   Updated: 2021/05/15 19:56:31 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/components.h"

static t_object	assign_vertex(char *v1, char *v2, char *v3)
{
	char		**tmp;
	t_tuple		p1;
	t_tuple		p2;
	t_tuple		p3;
	t_object	o;

	tmp = ft_split(v1, ',')
	p1.x = atof(tmp[0]);
	p1.y = atof(tmp[1]);
	p1.z = atof(tmp[2]);
	free_entry(&tmp);
	tmp = ft_split(v2, ',')
	p2.x = atof(tmp[0]);
	p2.y = atof(tmp[1]);
	p2.z = atof(tmp[2]);
	free_entry(&tmp);
	tmp = ft_split(v3, ',')
	p3.x = atof(tmp[0]);
	p3.y = atof(tmp[1]);
	p3.z = atof(tmp[2]);
	free_entry(&tmp);
	o = triangle(5, create_point(p1.x, p1.y, p1.z),
			create_point(p2.x, p2.y, p2.z), create_point(p3.x, p3.y, p3.z));
	
}

void	config_tr(t_initpara *initpara, t_vtx_par pt, char **entry_t) // paco diz, entry_t precisa de duas *
{
		t_object	o;
		t_color		cc;
		char		**tmp;

		pt.p1 = line_t[1];
		pt.p2 = line_t[2];
		pt.p3 = line_t[3];
		o = assign_vertex(pt.p1, pt.p2, pt.p3);
		tmp = ft_split(cor, ',');
		cc.red = (double)atof(temp[0]);
		cc.green = (double)atof(temp[1]);
		cc.blue = (double)atof(temp[2]);
		o.material = mat_par();
		o.material.color = scalar_color(cc, 0.003921569);
		o.material.specular = 0;
		list_obj(&initpara->objects, o);
		free_entry(&tmp);
}
