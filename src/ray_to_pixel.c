/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_to_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 21:10:58 by mde-figu          #+#    #+#             */
/*   Updated: 2021/05/27 14:25:58 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/canvas.h"

t_ray	ray_to_pixel(t_camera camera, double px, double py)
{
	t_beamoffset	p;
	t_matrix		a;
	t_tuple			pixel;
	t_tuple			origin;
	t_tuple			direction;

	p.xoffset = (px + 0.5) * camera.pixel_size;
	p.yoffset = (px + 0.5) * camera.pixel_size;
	p.world_x = camera.half_width - p.xoffset;
	p.world_y = camera.half_height - p.yoffset;
	a = inverse(camera.transform);
	pixel = matrix_x_vector(a, create_point(p.world_x, p.world_y, -1));
	origin = matrix_x_vector(a, create_point(0, 0, 0));
	free_matrix(&a);
	direction = quake_normalize(subtract_tuple(pixel, origin));
	p.r = ray(origin, direction);
	return (p.r);
}
