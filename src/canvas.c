/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:25:14 by mde-figu          #+#    #+#             */
/*   Updated: 2021/06/01 20:28:36 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/colors.h"
#include "../include/canvas.h"

void		store_img(t_imgg **l, t_data img)
{
	t_imgg	*tmp;

	if (lst_size_img(*l) == 0)
		*l = lst_new_img(img);
	else
	{
		tmp = *l;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = lst_new_img(img);
	}
}

void		arrange_pixels(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_canvas	write_pixel(t_canvas canvas,
						int width, int height, t_color color_init)
{
	canvas.pixel[width][height].red = color_init.red;
	canvas.pixel[width][height].green = color_init.green;
	canvas.pixel[width][height].blue = color_init.blue;
	return (canvas);

}

t_canvas		create_canvas(int width, int height)
{
	t_canvas	canvas;
	t_color		color_init;
	int	i;
	int j;

	color_init.red = 0.0;
	color_init.green = 0.0;
	color_init.blue = 0.0;
	canvas.pixel = (t_color **)malloc(width * sizeof(t_color *));
	i = 0;
	j = 0;
	canvas.width = width;
	canvas.height = heigth;
	while (j < height)
	{
	i = 0;
	canvas.pixel[j] = (t_color *)malloc(height * sizeof(t_color));
		while (i <= width)
		{
			write_pixel(canvas, i, j, color_init);
			i++;
		}
	j++;
	}
	return (canvas);
}

void		free_canvas(tcanvas canvas)
{
	int	j;

	j = 0
	while(j < canvas.height)
	{
		free (canvas.pixel[j]);
		j++;
	}
	free (canvas.pixel)
}
