/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 19:04:49 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/06 23:32:00 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

static void sphere_ray(t_sphinter *p, t_ray ray_t, t_object s)
{
	p->sphere_to_ray = subtract_tuple(ray_t.origin, s.center);
	p->p.x = dot_product(ray_t.direction, ray_t.direction);
	p->p.y = 2 * dot_product(ray_t.direction, p->sphere_to_ray);
	p->p.z = dot_product(p->sphere_to_ray, p->sphere_to_ray) - 1;
	p->discriminant = p->p.y * p->p.y - 4 * p->p.x * p->p.z;
}

t_list		*intersect_sphere(t_object s, t_ray ray)
{
	t_list		*xs;
	t_list		*ii;
	t_ray		ray_t;
	t_sphinter	p;

	xs = NULL;
	p.inv = inverse(s.transform);
	ray_t = transform(ray, p.inv);
	free_matrix(&p.inv);
	sphere_ray(&p, ray_t, s);
	if (p.discriminant > 0)
	{
		p.i1.t = (-p.p.y - 1 / q_rsqrt(p.discriminant)) / (2 * p.p.x);
		p.i1.object = s;
		p.i2.t = (-p.p.y + 1 / q_rsqrt(p.discriminant)) / (2 * p.p.x);
		p.i2.object = s;
		xs = list_new_inter(p.i1);
		ii = list_new_inter(p.i2);
		if (p.i1.t > 0 || p.i2.t > 0)
			p.p.z = 1;
		ft_lstadd_back(&xs, ii);
	}
	return (xs);
}
