/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 21:26:23 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/11 17:43:33 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

static void	set(t_pixiter c, t_canvas cv, t_imgg **img, t_initpara *initpara)
{
	int		x;
	int		y;
	t_color	cc;
	t_color	cor;
	t_data	im;

	im.image = mlx_new_image(initpara->mlx, c.xx, c.yy);
	im.address = mlx_get_data_addr(im.image, &im.bits_per_pixel,
				&im.line_length, &im.endian);
	y = 0;
	while(y < c.yy - 1)
	{
		x = 0;
		while (x < c.xx - 1)
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

void	image(t_initpara *initpara)
{
	t_canvasl	*tmp;
	t_pixiter		c;

	c.xx = initpara->res_x;
	c.yy = initpara->res_y;
	tmp = initpara->canvas;
	while (tmp->next)
	{
		set(c, tmp->content, &initpara->img, initpara);
		tmp = tmp->next;
	}
	set(c, tmp->content, &initpara->img, initpara);
	initpara->img_init = initpara->img;
}
