/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_cam.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 21:12:55 by mde-figu          #+#    #+#             */
/*   Updated: 2021/05/16 16:55:51 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"
#include "../include/canvas.h"
#include "../include/components.h"

void	config_cam(t_initpara *initpara, char *ps, char *n, char *fov)
{
	t_camera	c;
	t_matrix	m;
	char		**tmp;
	t_tuple		p1;
	t_tuple		p2;

	c = camera(initpara->res_x, initpara->res_y, atof(fov) * (M_PI / 180.0));
	tmp = ft_split(ps, ',');
	p1.x = atof(tmp[0]);
	p1.y = atof(tmp[1]);
	p1.z = atof(tmp[2]);
	free_entry(&tmp);
	tmp = ft_split(n, ',');
	p2.x = atof(tmp[0]);
	p2.y = atof(tmp[1]);
	p2.z = atof(tmp[2]);
	free_entry(&tmp);
	m = view_transform(create_point(p1.x, p1.y, p1.z),
				create_point(p2.x, p2.y, p2.z), create_vector(0.001, 1, 0.001));
	copy_matrix(&c.transform, m);
}
