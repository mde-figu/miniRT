/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_cam.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 21:12:55 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/17 19:00:27 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

void	config_cam(t_initpara *initpara, char *ps, char *n, char *fov)
{
	t_camera	c;
	t_matrix	m;
	char		**tmp;
	t_tuple		p1;
	t_tuple		p2;

	c = camera(initpara->res_x, initpara->res_y, ft_atof(fov) * (PIE / 180.0));
	tmp = ft_split(ps, ',');
	p1.x = ft_atof(tmp[0]);
	p1.y = ft_atof(tmp[1]);
	p1.z = ft_atof(tmp[2]);
	free_entry(&tmp);
	tmp = ft_split(n, ',');
	p2.x = ft_atof(tmp[0]);
	p2.y = ft_atof(tmp[1]);
	p2.z = ft_atof(tmp[2]);
	free_entry(&tmp);
	m = transform_cam(create_tuple(p1.x, p1.y, p1.z, 1),
			create_tuple(p2.x, p2.y, p2.z, 1),
			create_tuple(0.001, 1, 0.001, 0));
	copy_matrix(&c.transform, m);
	cameras(&initpara->cams, c);
	free_matrix(&m);
}
