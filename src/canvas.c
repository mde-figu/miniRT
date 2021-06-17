/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:25:14 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/17 18:15:59 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

void	store_img(t_imgg **l, t_data img)
{
	t_imgg	*tmp;

	if (list_size_img(*l) == 0)
		*l = list_new_img(img);
	else
	{
		tmp = *l;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = list_new_img(img);
	}
}

void	arrange_pixels(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->address + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	write_pixel(t_canvas *canvas,
						int width, int height, t_color color_init)
{
	canvas->pixel[width][height] = color_init;
}

void	create_canvas(t_canvas *canvas, int w, int h)
{
	t_color		black;
	int			i;
	int			j;

	i = -1;
	black = create_color(0, 0, 0);
	canvas->width = w;
	canvas->height = h;
	canvas->pixel = (t_color **)malloc(sizeof(t_color *) * h);
	while (++i < h)
	{
		canvas->pixel[i] = (t_color *)malloc(sizeof(t_color) * w);
	}
	i = -1;
	while (++i < h)
	{
		j = -1;
		while (++j < w)
		{
			canvas->pixel[i][j] = black;
		}
	}
}

void	free_canvas(t_canvas canvas)
{
	int	j;

	j = 0;
	while (j < canvas.height)
	{
		free(canvas.pixel[j]);
		j++;
	}
	free(canvas.pixel);
}
