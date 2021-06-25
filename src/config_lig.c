/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_lig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:42:01 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/25 16:56:42 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

void	config_lig(t_initpara *initpara, char *ps, char *br, char *col)
{
	char		**tmp1;
	char		**tmp2;
	t_color		c;
	t_tuple		p;
	float		b;

	tmp1 = ft_split(ps, ',');
	p.x = ft_atof(tmp1[0]);
	p.y = ft_atof(tmp1[1]);
	p.z = ft_atof(tmp1[2]);
	b = ft_atof(br);
	tmp2 = ft_split(col, ',');
	c.red = (double)ft_atoi(tmp2[0]);
	c.green = (double)ft_atoi(tmp2[1]);
	c.blue = (double)ft_atoi(tmp2[2]);
	light(&initpara->lighting, point_light(create_tuple(p.x, p.y, p.z, 1),
			scalar_color(scalar_color(c, 0.003921569), b)));
	free_entry(&tmp1);
	free_entry(&tmp2);
}
