/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 21:58:39 by mde-figu          #+#    #+#             */
/*   Updated: 2021/05/27 12:17:51 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/canvas.h"

t_ray	ray(t_tuple origin, t_tuple direction)
{
	t_ray	r;

	r.origin = origin;
	r.direction = direction;
	return (r);
}


t_tuple	posit(t_ray ray, double t)
{
	t_tuple p;

	p = add_tuple(ray.origin, scale_tuple(ray.direction, t));
	return (p);
}
