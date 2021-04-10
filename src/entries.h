/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entries.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:23:16 by mde-figu          #+#    #+#             */
/*   Updated: 2021/04/09 19:40:34 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTRIES_H
# define ENTRIES_H

#include "src/canvas.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct			s_initpara
{
	int			res_x;
	int			res_y;
	int			num_objects;
	bool		save;
	bool		lightonoff;
	t_color		init_color;
	t_color		ambient;
	t_canvas 	*c_canvas;
	t_light		*lighting;
	t_objects 	*objects
	t_imgg		*img;
	t_imgg		*img_init;
	void		*mlx;
	void		*win;
}