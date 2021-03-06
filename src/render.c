/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 20:23:09 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/23 18:23:37 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

void	render(t_canvas *canvas, t_camera camera, t_initpara initpara)
{
	int			x;
	int			y;
	t_ray		ray;
	t_color		color;

	create_canvas(canvas, camera.hsize, camera.vsize);
	y = 0;
	while (y < camera.vsize - 1)
	{
		x = 0;
		while (x < camera.hsize - 1)
		{
			ray = ray_to_pixel(camera, x, y);
			color = list_color(initpara, ray);
			write_pixel(canvas, x, y, color);
			loading_bar(x / (camera.hsize - 1), camera.hsize, 0);
			x++;
		}
		y++;
	}
}
