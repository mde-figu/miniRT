/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 21:26:23 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/01 20:31:59 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"
#include "../include/parameters.h"
#include "../include/components.h"
#include "../include/canvas.h"

static void	set(t_coord c, t_canvas cv, t_imgg **img, t_initpara *conf)
{
	int		x;
	int		y;
	t_color	cc;
	t_color	cor;
	t_data	im;

	im.img = mlx_new_image(config->mlx, c.i, c.j);
	im.addr = mlx_get_data_addr(im.img, &im.bits_per_pixel,
				&im.line_length, &im.endian);
	y = 0;
	while(y < c.i - 1)
	{
		x = 0;
		while (x < c.j - 1)
		{
			cor = cv.pixel[x][y];
			cc.red = color_bool(cor.red);
			cc.green = color_bool(cor.green);
			cc.blue = color_bool(cor.blue);
			arrange_pixels(&im, x, y, color_to_rgb(cc.red, cc.green, cc.blue));
			x++;
		}
		y++;
	}
	store_img(img, im);
}

void	image(t_initpara *conf)
{
	t_canvasl	tmp;
	t_coord		c;

	c.i = conf->r_x;
	c.j = conf->r_y;
	tmp = conf->canvas;
	while (tmp->next)
	{
		set(c, tmp->content, &conf->img, conf);
		tmp = tmp->next;
	}
	set(c, tmp->content, &conf->img, conf);
	conf->img_init = conf->img;
}
