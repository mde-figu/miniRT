/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:21:39 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/25 20:15:06 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

t_object	square(void)
{
	t_object	p;

	p.id = 4;
	p.type = "square";
	p.center = create_tuple(0, 0, 0, 1);
	p.transform = identity();
	p.material.color = create_color(1, 1, 1);
	p.material.ambient = 0.1;
	p.material.diffuse = 0.5;
	p.material.specular = 0.9;
	p.material.shininess = 200;
	p.minimum = -INFINITY;
	p.maximum = INFINITY;
	p.closed = false;
	p.p1 = create_tuple(0, 0, 0, 1);
	p.p2 = create_tuple(0, 0, 0, 1);
	p.p3 = create_tuple(0, 0, 0, 1);
	p.e1 = create_tuple(0, 0, 0, 1);
	p.e2 = create_tuple(0, 0, 0, 1);
	p.normal = create_tuple(0, 0, 0, 1);
	return (p);
}
