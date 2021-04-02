/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:00:31 by mde-figu          #+#    #+#             */
/*   Updated: 2021/04/01 18:15:09 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct			s_canvas
{
	int				width;
	int				height;
	t_color			**pixel;
}						t_canvas;

typedef struct			s_pixel
{
	int				x;
	int				y;
}						t_pixel;

typedef struct			s_color
{
	double				red;
	double				green;
	double				brue;
}						t_color;