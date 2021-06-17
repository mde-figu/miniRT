/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:25:14 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/16 18:28:15 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/entries.h"

void		store_img(t_imgg **l, t_data img)
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

void	create_canvas(t_canvas *canvas, int width, int height)
{
	t_color		color_init;
	int			i;
	int			j;

	color_init.red = 0.0;
	color_init.green = 0.0;
	color_init.blue = 0.0;
	canvas->width = width;
	canvas->height = height;
	i = 0;
	j = 0;
	canvas->pixel = (t_color **)malloc(height * sizeof(t_color *));
	while (++i < height)
	{
		canvas->pixel[j] = (t_color *)malloc(height * sizeof(t_color));
	}
	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
		{
			write_pixel(canvas, i, j, color_init);
		}
	}
}

void		free_canvas(t_canvas canvas)
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
