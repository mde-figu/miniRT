/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 20:23:09 by mde-figu          #+#    #+#             */
/*   Updated: 2021/05/27 12:05:52 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/components.h"
#include "../include/entries.h"

t_canvas	render(t_camera camera, t_initpara initpara)
{
	t_canvas	image;
	int			x;
	int			y;
	t_ray		ray;
	t_color		col;

	image = create_canvas(camera.hsize, camera.vsize);
	y = 0;
	while (y < camera.vsize - 1)
	{
		x = 0;
		while (x <camera.hsize - 1)
		{
			ray = ray_to_pixel(camera, x, y);
			col = list_color(initpara, ray);
			write_pixel(&image, x, y, color);
			x++;
		}
		y++;
	}
	return (image);
}
