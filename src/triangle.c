/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:53:00 by mde-figu          #+#    #+#             */
/*   Updated: 2021/05/19 19:20:47 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parameters.h"
#include "../include/components.h"

t_object	triangle(int id, t_tuple p1, t_tuple p2, t_tuple p3)
{
	t_object	p;

	p.id = id;
	p.type = "triangle";
	p.transform = identity();
	p.material.color = create_color(1, 1, 1);
	p.material.ambient = 0.1;
	p.material.diffuse = 0.9;
	p.material.specular = 0.9;
	p.material.shininess = 200;
	p.minimum = -INFINITY;
	p.maximum = INFINITY;
	p.closed = false;
	p.p1 = p1;
	p.p2 = p2;
	p.p3 = p3;
	p.e1 = subtract_tuple(p2, p1);
	p.e2 = subtract_tuple(p3, p1);
	p.normal = quake_normalize(cross(p.e2, p.e1));

}