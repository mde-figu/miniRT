/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:25:01 by mde-figu          #+#    #+#             */
/*   Updated: 2021/05/19 19:26:06 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/components.h"

t_object	sphere(void)
{
	t_object	p;

	p.id = 3;
	p.type = "sphere";
	p.center = create_point(0, 0, 0);
	p.transform = identity();
	p.material.color = create_color(1, 1, 1);
	p.material.ambient = 0.1;
	p.material.diffuse = 0.9;
	p.material.specular = 0.9;
	p.material.shininess = 200;
	p.minimum = -INFINITY;
	p.maximum = INFINITY;
	p.closed = false;
	p.p1 = create_point(0, 0, 0);
	p.p2 = create_point(0, 0, 0);
	p.p3 = create_point(0, 0, 0);
	p.e1 = create_point(0, 0, 0);
	p.e2 = create_point(0, 0, 0);
	p.normal = create_point(0, 0, 0);
	return (p);
}